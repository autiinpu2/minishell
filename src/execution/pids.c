/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 06:52:38 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/28 08:17:26 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	built_in_exeption(t_cmd *cmd, t_built_in *built_in)
{
	if (is_built_in(cmd->function_name))
	{
		run_built_in(cmd->function_name, built_in);
	}
	return (built_in->exit_code);
}

void	create_processes(t_tab_cmd *cmd, char **envp, t_built_in *built_in)
{
	int		i;
	t_cmd	*tab;

	i = 0;
	tab = cmd->tab;
	while (tab[i].function_name)
	{
		if (built_in_exeption(tab, built_in))
		{
			i++;
			continue ;
		}
		tab[i].pid = fork();
		if (tab[i].pid < 0)
		{
			perror("fork");
			close_all_fds(tab);
			free_tab_cmd(cmd);
			exit(1);
		}
		if (tab[i].pid == 0)
			run_cmd(cmd, envp, i);
		i++;
	}
}

int	wait_all_pids(t_tab_cmd *cmd)
{
	int	i;
	int	exit_code;
	int	status;

	i = 0;
	exit_code = 14;
	while (cmd->tab[i].function_name)
	{
		status = -1;
		waitpid(cmd->tab[i].pid, &status, 0);
		if (WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_code = 128 + WTERMSIG(status);
		i++;
	}
	return (exit_code);
}
