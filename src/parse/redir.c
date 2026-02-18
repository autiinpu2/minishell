/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:02:09 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/18 03:27:07 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	setup_redirs(t_data *data)
{
	int	i;
	int	exit;

	i = 0;
	exit = 0;
	while (i < data->cmds->redir_count)
	{
		if (data->cmds->redirs[i].type == 1)
			exit = redir_1(data, i);
		else if (data->cmds->redirs[i].type == 2)
			exit = redir_2(data, i);
		else if (data->cmds->redirs[i].type == 3)
			exit = redir_3(data, i);
		else if (data->cmds->redirs[i].type == 4)
			exit = redir_4(data, i);
		else if (exit)
			return (1);
	}
	return (0);
}

void	init_redirs(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!is_redir(data->cmds->args[i]))
		i++;
	while (j < data->cmds->redir_count)
	{
		if (!ft_strcmp(data->cmds->args[i], ">"))
			data->cmds->redirs[j].type = 1;
		else if (!ft_strcmp(data->cmds->args[i], ">>"))
			data->cmds->redirs[j].type = 2;
		else if (!ft_strcmp(data->cmds->args[i], "<"))
			data->cmds->redirs[j].type = 3;
		else
			data->cmds->redirs[j].type = 4;
		data->cmds->redirs[j].file = ft_strdup(data->cmds->args[i + 1]);
		j++;
		i += 2;
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
	int	i;
	int	j;
	int	exit;

	i = 0;
	j = 0;
	exit = 0;
	while (data->cmds->args[i])
	{
		if (is_redir(data->cmds->args[i]))
		{
			data->cmds->redir_count = redir_count(data->cmds->args);
			data->cmds->redirs = ft_calloc(data->cmds->redir_count + 1,
					sizeof(t_redir));
			check_order(data);
			init_redirs(data);
			exit = setup_redirs(data);
			if (exit)
				return (1);
		}
		i++;
	}
	return (0);
}
