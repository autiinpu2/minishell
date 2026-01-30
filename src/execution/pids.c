/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 06:52:38 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/30 10:58:19 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	built_in_exeption(t_cmd *cmd, t_built_in *built_in, int i)
{
	if (!built_in)
		return (false);
	if (is_built_in(cmd->function_name))
	{
		run_built_in(cmd->function_name, built_in, i);
		return (true);
	}
	return (false);
}

void	create_processes(t_tab_cmd *tab, char **envp, t_built_in *built_in)
{
	int		i;
	t_cmd	*cmd;

	i = 0;
	cmd = tab->cmd;
	while (cmd[i].function_name)
	{
		if (built_in_exeption(&cmd[i], built_in, i))
		{
			i++;
			continue ;
		}
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
		i++;
	}
}

int	wait_all_pids(t_tab_cmd *tab)
{
	int	i;
	int	exit_code;
	int	status;

	i = 0;
	exit_code = 14;
	while (tab->cmd[i].function_name)
	{
		status = -1;
		waitpid(tab->cmd[i].pid, &status, 0);
		if (WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_code = 128 + WTERMSIG(status);
		i++;
	}
	return (exit_code);
}
