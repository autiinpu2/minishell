/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 05:13:28 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/03 00:41:13 by mcomin           ###   ########.fr       */
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
		ft_dprintf(2, "minishell: %s: No such file or directory\n",
			data->cmds[cmd_idx].redirs[i].file);
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
		ft_dprintf(2, "minishell: %s: No such file or directory\n",
			data->cmds[cmd_idx].redirs[i].file);
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
		ft_dprintf(2, "minishell: %s: No such file or directory\n",
			data->cmds[cmd_idx].redirs[i].file);
		return (1);
	}
	return (0);
}

int	redir_4(t_data *data, int i, int cmd_idx)
{
	int				fd;
	char			*num_str;
	char			*name;

	num_str = get_rand_numbers(8);
	if (!num_str)
		return (1);
	name = ft_strjoin("/tmp/sh-thd-", num_str);
	free_single(num_str);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		free_single(name);
		return (1);
	}
	data->cmds[cmd_idx].infile = fd;
	read_heredoc(data->cmds[cmd_idx].redirs[i].file, data->cmds[cmd_idx]);
	data->cmds[cmd_idx].infile = open(name, O_RDONLY);
	unlink(name);
	free_single(name);
	return (0);
}
