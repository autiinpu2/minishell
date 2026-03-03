/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:02:09 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/03 02:45:04 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	setup_redirs(t_data *data, int cmd_idx)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < data->cmds[cmd_idx].redir_count)
	{
		if (data->cmds[cmd_idx].redirs[i].type == 1)
			error = redir_1(data, i, cmd_idx);
		else if (data->cmds[cmd_idx].redirs[i].type == 2)
			error = redir_2(data, i, cmd_idx);
		else if (data->cmds[cmd_idx].redirs[i].type == 3)
			error = redir_3(data, i, cmd_idx);
		else if (data->cmds[cmd_idx].redirs[i].type == 4)
			error = redir_4(data, i, cmd_idx);
		if (error)
			return (1);
		i++;
	}
	return (0);
}

char	**trim_args(char **old)
{
	int		i;
	int		j;
	char	**new_arg;

	i = 0;
	j = 0;
	new_arg = ft_calloc(tab_size(old) - is_in_tab(old, "REDIR_MAKER") + 1,
			sizeof(char *));
	if (!new_arg)
	{
		free_tab(old);
		return (NULL);
	}
	while (old[i])
	{
		if (ft_strcmp(old[i], "REDIR_MARKER"))
		{
			new_arg[j] = ft_strdup(old[i]);
			j++;
		}
		i++;
	}
	free_tab(old);
	return (new_arg);
}

void	process_redir(t_data *data, int cmd_idx, int i, int redir_idx)
{
	char	**args;

	args = data->cmds[cmd_idx].args;
	if (!ft_strcmp(args[i], ">"))
		data->cmds[cmd_idx].redirs[redir_idx].type = 1;
	else if (!ft_strcmp(args[i], ">>"))
		data->cmds[cmd_idx].redirs[redir_idx].type = 2;
	else if (!ft_strcmp(args[i], "<"))
		data->cmds[cmd_idx].redirs[redir_idx].type = 3;
	else if (!ft_strcmp(args[i], "<<"))
		data->cmds[cmd_idx].redirs[redir_idx].type = 4;
	data->cmds[cmd_idx].redirs[redir_idx].file = ft_strdup(args[i + 1]);
	free(args[i]);
	free(args[i + 1]);
	args[i] = ft_strdup("REDIR_MARKER");
	args[i + 1] = ft_strdup("REDIR_MARKER");
}

void	init_redirs(t_data *data, int cmd_idx)
{
	int		i;
	int		redir_idx;
	char	**args;

	i = 0;
	redir_idx = 0;
	args = data->cmds[cmd_idx].args;
	while (args && args[i])
	{
		if (is_redir(args[i]))
		{
			if (!args[i + 1])
				break ;
			process_redir(data, cmd_idx, i, redir_idx);
			redir_idx++;
			i++;
		}
		i++;
	}
	data->cmds[cmd_idx].args = trim_args(data->cmds[cmd_idx].args);
}

int	handle_redir(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmds[i].args)
	{
		data->cmds[i].redir_count = redir_count(data->cmds[i].args);
		if (data->cmds[i].redir_count > 0)
		{
			data->cmds[i].redirs = ft_calloc(data->cmds[i].redir_count + 1,
					sizeof(t_redir));
			init_redirs(data, i);
			if (setup_redirs(data, i))
				return (1);
		}
		i++;
	}
	return (0);
}
