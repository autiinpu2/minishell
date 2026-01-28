/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 06:53:48 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/28 07:33:16 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	run_cmd(t_tab_cmd *cmd, char **envp, int i)
{
	if (!cmd->tab[i].path)
	{
		write(2, cmd->tab[i].function_name,
			ft_strlen(cmd->tab[i].function_name));
		write(2, ": command not found\n", 21);
		exit(127);
	}
	if (cmd->tab[i].infile != STDIN_FILENO)
	{
		dup2(cmd->tab[i].infile, STDIN_FILENO);
		close(cmd->tab[i].infile);
	}
	if (cmd->tab[i].outfile != STDOUT_FILENO)
	{
		dup2(cmd->tab[i].outfile, STDOUT_FILENO);
		close(cmd->tab[i].outfile);
	}
	close_every_pipe(cmd, i);
	execve(cmd->tab[i].path, cmd->tab[i].args, envp);
	perror("execve failed");
	free_tab_cmd(cmd);
	free_tab(envp);
	exit(1);
}
