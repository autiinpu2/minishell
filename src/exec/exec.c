/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 06:00:50 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/05 04:54:43 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "exec.h"

int	run_built_in(t_cmd cmd, t_env *env, t_exec exec)
{
	(void)env;
	(void)exec;
	int exit_code;
	exit_code = 2;
	if (!ft_strcmp(cmd.function_name, "env"))
		exit_code = ft_env(env, cmd);
	else if (!ft_strcmp(cmd.function_name, "pwd"))
		//exit_code = ft_pwd(env);
		return 0 ;
	else if (!ft_strcmp(cmd.function_name, "cd"))
		//exit_code = ft_cd(cmd.args[1]);
		return 0 ;
	else if (!ft_strcmp(cmd.function_name, "exit"))
		//exit_code = ft_exit(cmd.args[1]);
		return 0 ;
	else if (!ft_strcmp(cmd.function_name, "unset"))
		//exit_code = ft_unset(env);
		return 0 ;
	return (exit_code);
}

void	run_processes(t_env *env, t_data *data, t_exec *exec)
{
	int		i;

	i = 0;
	while (data->cmds[i].function_name)
	{
		if (data->cmds[i].is_built_in)
			run_built_in(data->cmds[i], env, exec[i]);
		else
			//run_forks(data->cmds[i], env, exec[i]);
		i++;
	}
}

t_exec *init_exec(t_data *data)
{
	t_exec	*exec;
	size_t	i;

	i = 0;
	exec = ft_calloc(data->size, sizeof(t_exec));
	while (i < data->size)
	{
		exec[i].exist = true;
		exec[i].exist = 0;
		exec[i].is_built_in = is_built_in(data->cmds[i].function_name);
	}
	return (exec);
}

int	exec(t_env *env, t_data	*data)
{
	t_exec	*exec;

	exec = init_exec(data);
	run_processes(env, data, exec);
	wait_all_pids(data, exec);
	
	return (exec[data->size - 1].exit_code);
}

int wait_all_pids(t_data *data, t_exec *exec)
{
	size_t i;
	int status;
	int exit_code;

	i = 0;
	exit_code = 0;
	while (i < data->size)
	{
		if (data->cmds[i].is_built_in == true)
		{
			exit_code = exec[i].exit_code;
		}
		else
		{
			waitpid(data->cmds[i].pid, &status, 0);
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = 128 + WTERMSIG(status);
		}
		i++;
	}
	return (exit_code);
}
