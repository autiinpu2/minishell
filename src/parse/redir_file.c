/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 05:13:28 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/17 06:09:08 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int redir_1 (t_data *data, int i)
{
	int fd;
	
	if (data->cmds->outfile)
		close(data->cmds->outfile);
	fd = open(data->cmds->redirs[i].file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		data->exit_code = 1;
		return (1);   
	}
	data->cmds->outfile = fd;
	return (0);
}

int redir_2 (t_data *data, int i)
{
	int fd;
	
	if (data->cmds->outfile)
		close(data->cmds->outfile);
	fd = open(data->cmds->redirs[i].file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		data->exit_code = 1;
		return (1);   
	}
	data->cmds->outfile = fd;
	return (0);
}

int redir_3 (t_data *data, int i)
{
	int fd;
	
	if (data->cmds->outfile)
		close(data->cmds->outfile);
	fd = open(data->cmds->redirs[i].file, O_RDONLY);
	if (fd == -1)
	{
		data->exit_code = 1;
		return (1);   
	}
	data->cmds->outfile = fd;
	return (0);
}

int redir_4 (t_data *data, int i)
{
	int fd;
	
	(void)i;
	if (data->cmds->outfile)
		close(data->cmds->outfile);
	//fd = heredoc
	fd = 0; 
	if (fd == -1)
	{
		data->exit_code = 1;
		return (1);   
	}
	data->cmds->outfile = fd;
	return (0);
}