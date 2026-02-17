/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 05:22:21 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/17 01:09:32 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "exec.h"

int	run_built_in(t_cmd cmd, t_data *data)
{
	int	exit_code;

	exit_code = 2;
	if (!ft_strcmp(cmd.function_name, "env"))
		exit_code = ft_env(data, cmd);
	else if (!ft_strcmp(cmd.function_name, "pwd"))
		exit_code = ft_pwd(data, cmd);
	else if (!ft_strcmp(cmd.function_name, "cd"))
	{
		ft_cd(data, cmd);
		return (data->exit_code);
	}
	else if (!ft_strcmp(cmd.function_name, "exit"))
		exit_code = ft_exit(data, cmd);
	else if (!ft_strcmp(cmd.function_name, "unset"))
		exit_code = ft_unset(data, cmd);
	else if (!ft_strcmp(cmd.function_name, "export"))
		exit_code = ft_export(data, cmd);
	else if (!ft_strcmp(cmd.function_name, "echo"))
		exit_code = ft_echo(cmd);
	else if (!ft_strcmp(cmd.function_name, "mark"))
		exit_code = ft_mark(data, cmd);
	return (exit_code);
}

void	run_processes(t_data *data)
{
	int		i;

	i = 0;
	while (data->cmds[i].function_name)
	{
		if (data->cmds[i].is_built_in)
			data->exit_code = run_built_in(data->cmds[i], data);
		else
			run_forks(data->cmds[i], data, i);
		i++;
	}
}

int	exec(t_data	*data)
{
	run_processes(data);
	data->exit_code = wait_all_pids(data);
	return (data->exit_code);
}

int	wait_all_pids(t_data *data)
{
	size_t	i;
	int		status;
	int		exit_code;

	i = 0;
	exit_code = 0;
	signal(SIGINT, SIG_IGN);
	while (i < data->size)
	{
		if (data->cmds[i].is_built_in == true)
			exit_code = data->exit_code;
		else
		{
			if (waitpid(data->cmds[i].pid, &status, 0) != -1)
			{
				if (WIFEXITED(status))
					exit_code = WEXITSTATUS(status);
				else if (WIFSIGNALED(status))
					exit_code = 128 + WTERMSIG(status);
			}
		}
		i++;
	}
	signals();
	return (exit_code);
}
