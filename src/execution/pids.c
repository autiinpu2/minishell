/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 06:52:38 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 01:08:55 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	built_in_exeption(t_cmd cmd, t_built_in *built_in, int i)
{
	if (!built_in)
		return (false);
	if (is_built_in(cmd.function_name))
	{
		run_built_in(cmd.function_name, built_in, i);
		return (true);
	}
	return (false);
}

void	create_processes(t_tab_cmd *tab, char **envp)
{
	int		i;
	t_cmd	*cmd;

	i = 0;
	cmd = tab->cmd;
	while (cmd[i].function_name)
	{
		cmd[i].pid = fork();
		if (cmd[i].pid < 0)
		{
			perror("fork");
			close_all_fds(&cmd[i]);
			free_tab_cmd(tab);
			exit(1);
		}
		if (cmd[i].pid == 0)
			run_cmd(tab, envp, i);
		if (cmd[i].infile > 2)
			close(cmd[i].infile);
		if (cmd[i].outfile > 2)
			close(cmd[i].outfile);
		i++;
		close_every_pipe(tab, i);
	}
}

int wait_all_pids(t_tab_cmd *tab)
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
			i++;
			continue ;
		}
		waitpid(tab->cmd[i].pid, &status, 0);
		if (WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_code = 128 + WTERMSIG(status);
		i++;
	}
	return (exit_code);
}
