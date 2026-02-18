/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:02:09 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/18 05:07:52 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	setup_redirs(t_data *data, int cmd_idx)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < data->cmds->redir_count)
	{
		if (data->cmds[cmd_idx].redirs[i].type == 1)
			error = redir_1(data, i);
		else if (data->cmds[cmd_idx].redirs[i].type == 2)
			error = redir_2(data, i);
		else if (data->cmds[cmd_idx].redirs[i].type == 3)
			error = redir_3(data, i);
		else if (data->cmds[cmd_idx].redirs[i].type == 4)
			error = redir_4(data, i);
		if (error)
			return (1);
		i++;
	}
	return (0);
}

void	init_redirs(t_data *data, int cmd_idx)
{
	int	arg_idx;
	int	redir_idx;

	arg_idx = 0;
	redir_idx = 0;
	while (data->cmds[cmd_idx].args[arg_idx])
	{
		if (is_redir(data->cmds[cmd_idx].args[arg_idx]))
		{
			if (!ft_strcmp(data->cmds[cmd_idx].args[arg_idx], ">"))
				data->cmds[cmd_idx].redirs[redir_idx].type = 1;
			else if (!ft_strcmp(data->cmds[cmd_idx].args[arg_idx], ">>"))
				data->cmds[cmd_idx].redirs[redir_idx].type = 2;
			else if (!ft_strcmp(data->cmds[cmd_idx].args[arg_idx], "<"))
				data->cmds[cmd_idx].redirs[redir_idx].type = 3;
			else if (!ft_strcmp(data->cmds[cmd_idx].args[arg_idx], "<<"))
				data->cmds[cmd_idx].redirs[redir_idx].type = 4;
			data->cmds[cmd_idx].redirs[redir_idx].file = ft_strdup(data->cmds[cmd_idx].args[arg_idx + 1]);
			redir_idx++;
			arg_idx++;
		}
		arg_idx++;
	}
}

void	check_order(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmds->args[i])
	{
		if ((i == 0) && (is_redir(data->cmds->args[i])))
		{
			
		}
	}
}

int	redir_count(char **args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[i])
	{
		if (is_redir(args[i]))
			count++;
		i++;
	}
	return (count);
}

int	handle_redir(t_data *data)
{
	int i;

	i = 0;
	while (data->cmds[i].args)
	{
		data->cmds[i].redir_count = redir_count(data->cmds[i].args);
		if (data->cmds[i].redir_count > 0)
		{
			data->cmds[i].redirs = ft_calloc(data->cmds[i].redir_count + 1, sizeof(t_redir));
			init_redirs(data, i);
			if (setup_redirs(data, i))
				return (1);
		}
		i++;
	}
	return (0);
}
