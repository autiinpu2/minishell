/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 06:53:48 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/30 03:35:40 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	run_cmd(t_tab_cmd *tab, char **envp, int i)
{
	if (!tab->cmd[i].path)
	{
		write(2, tab->cmd[i].function_name,
			ft_strlen(tab->cmd[i].function_name));
		write(2, ": command not found\n", 21);
		exit(127);
	}
	if (tab->cmd[i].infile != STDIN_FILENO)
	{
		dup2(tab->cmd[i].infile, STDIN_FILENO);
		close(tab->cmd[i].infile);
	}
	if (tab->cmd[i].outfile != STDOUT_FILENO)
	{
		dup2(tab->cmd[i].outfile, STDOUT_FILENO);
		close(tab->cmd[i].outfile);
	}
	close_every_pipe(tab, i);
	execve(tab->cmd[i].path, tab->cmd[i].args, envp);
	perror("execve failed");
	free_tab_cmd(tab);
	free_tab(envp);
	exit(1);
}
