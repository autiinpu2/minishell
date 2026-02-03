/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 06:00:50 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 11:16:03 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "exec.h"

int	run_built_in(t_cmd cmd, t_env *env, t_exec exec)
{
	int exit_code;
	exit_code = 2;
	if (!ft_strcmp(cmd.function_name, "env"))
		exit_code = ft_env(env, cmd);
	// else if (!ft_strcmp(cmd.function_name, "pwd"))
	// 	exit_code = ft_pwd(env);
	// else if (!ft_strcmp(cmd.function_name, "cd"))
	// 	exit_code = ft_cd(cmd.args[1]);
	// else if (!ft_strcmp(cmd.function_name, "exit"))
	// 	exit_code = ft_exit(cmd.args[1]);
	// else if (!ft_strcmp(cmd.function_name, "unset"))
	// 	exit_code = ft_unset(env);
	return (exit_code);
}

void	run_processes(t_env *env, t_tab_cmd	*tab, t_exec *exec)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	cmd = tab->cmd;
	while (cmd[i].function_name)
	{
		if (cmd[i].is_build_in)
			run_built_in(cmd[i], env, exec[i]);
		else
			run_forks(cmd[i], env, exec[i]);
		i++;
	}
}

t_exec *init_exec(t_tab_cmd *tab)
{
	t_exec	*exec;
	size_t	i;

	i = 0;
	exec = ft_calloc(tab->size, sizeof(t_exec));
	while (i < tab->size)
	{
		exec[i].exist = true;
		exec[i].exist = 0;
		exec[i].is_built_in = is_built_in(tab->cmd[i].function_name);
	}
	return (exec);
}

int	exec(t_env *env, t_tab_cmd	*tab)
{
	t_exec	*exec;

	exec = init_exec(tab);
	run_processes(env, tab, exec);
	wait_all_pids(tab, exec);
	
	return (exec[tab->size - 1].exit_code);
}

int wait_all_pids(t_tab_cmd *tab, t_exec *exec)
{
	size_t i;
	int status;
	int exit_code;

	i = 0;
	exit_code = 0;
	while (i < tab->size)
	{
		if (tab->cmd[i].is_build_in == true)
		{
			exit_code = exec[i].exit_code;
		}
		else
		{
			waitpid(tab->cmd[i].pid, &status, 0);
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = 128 + WTERMSIG(status);
		}
		i++;
	}
	return (exit_code);
}
