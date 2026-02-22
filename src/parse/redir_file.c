/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 05:13:28 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/18 08:05:59 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	redir_1(t_data *data, int i, int cmd_idx)
{
	int	fd;

	if (data->cmds[cmd_idx].outfile > 2)
		close(data->cmds[cmd_idx].outfile);
	fd = open(data->cmds[cmd_idx].redirs[i].file,
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data->cmds[cmd_idx].outfile = fd;
	data->cmds[cmd_idx].is_outfile_pipe = false;
	if (fd == -1)
	{
		data->exit_code = 1;
		ft_dprintf(2, "minishell: %s: No such file or directory\n", data->cmds[cmd_idx].redirs[i].file);
		return (1);
	}
	return (0);
}

int	redir_2(t_data *data, int i, int cmd_idx)
{
	int	fd;

	if (data->cmds[cmd_idx].outfile > 2)
		close(data->cmds[cmd_idx].outfile);
	fd = open(data->cmds[cmd_idx].redirs[i].file,
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	data->cmds[cmd_idx].outfile = fd;
	data->cmds[cmd_idx].is_outfile_pipe = false;
	if (fd == -1)
	{
		data->exit_code = 1;
		ft_dprintf(2, "minishell: %s: No such file or directory\n", data->cmds[cmd_idx].redirs[i].file);
		return (1);
	}
	return (0);
}

int	redir_3(t_data *data, int i, int cmd_idx)
{
	int	fd;

	if (data->cmds[cmd_idx].infile > 2)
		close(data->cmds[cmd_idx].infile);
	fd = open(data->cmds[cmd_idx].redirs[i].file, O_RDONLY);
	data->cmds[cmd_idx].infile = fd;
	if (fd < 0)
	{
		data->exit_code = 1;
		ft_dprintf(2, "minishell: %s: No such file or directory\n", data->cmds[cmd_idx].redirs[i].file);
		return (1);
	}
	return (0);
}

int	redir_4(t_data *data, int i, int cmd_idx)
{
	int	fd;

	(void)i;
	if (data->cmds[cmd_idx].infile > 2)
		close(data->cmds[cmd_idx].infile);
		//fd = heredoc
	fd = 0;
	data->cmds[cmd_idx].infile = fd;
	if (fd < 0)
	{
		data->exit_code = 1;
		ft_dprintf(2, "minishell: %s: No such file or directory\n", data->cmds[cmd_idx].redirs[i].file);
		return (1);
	}
	return (0);
}
