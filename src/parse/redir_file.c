/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 05:13:28 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/18 05:07:28 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	redir_1(t_data *data, int i, int cmd_idx)
{
	int	fd;

	if (data->cmds[cmd_idx].outfile)
		close(data->cmds[cmd_idx].outfile);
	fd = open(data->cmds[cmd_idx].redirs[i].file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		data->exit_code = 1;
		return (1);
	}
	data->cmds[cmd_idx].outfile = fd;
	return (0);
}

int	redir_2(t_data *data, int i, int cmd_idx)
{
	int	fd;

	if (data->cmds[cmd_idx].outfile)
		close(data->cmds[cmd_idx].outfile);
	fd = open(data->cmds[cmd_idx].redirs[i].file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		data->exit_code = 1;
		return (1);
	}
	data->cmds[cmd_idx].outfile = fd;
	return (0);
}

int	redir_3(t_data *data, int i, int cmd_idx)
{
	int	fd;

	if (data->cmds[cmd_idx].infile)
		close(data->cmds[cmd_idx].infile);
	fd = open(data->cmds[cmd_idx].redirs[i].file, O_RDONLY);
	if (fd < 0)
	{
		data->exit_code = 1;
		return (1);
	}
	data->cmds[cmd_idx].infile = fd;
	return (0);
}

int	redir_4(t_data *data, int i, int cmd_idx)
{
	int	fd;

	(void)i;
	if (data->cmds[cmd_idx].infile)
		close(data->cmds[cmd_idx].infile);
	//fd = heredoc
	fd = 0;
	if (fd < 0)
	{
		data->exit_code = 1;
		return (1);
	}
	data->cmds[cmd_idx].infile = fd;
	return (0);
}
