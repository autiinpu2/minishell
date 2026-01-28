/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 06:51:39 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/28 06:52:11 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_all_fds(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd[i].function_name)
	{
		if (cmd[i].infile > 2)
			close(cmd[i].infile);
		if (cmd[i].outfile > 2)
			close(cmd[i].outfile);
		i++;
	}
}

void	close_every_pipe(t_tab_cmd *cmd, int i)
{
	int	j;

	j = 0;
	while (cmd->tab[j].function_name)
	{
		if (j != i)
		{
			if (cmd->tab[j].infile_is_pipe)
				close (cmd->tab[j].infile);
			if (cmd->tab[j].outfile_is_pipe)
				close (cmd->tab[j].outfile);
		}
		j++;
	}
}
