/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:35:09 by mcomin            #+#    #+#             */
/*   Updated: 2026/01/31 09:54:37 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd		ft_init_cmd_is_pipe(t_tab_cmd *tab, int current)
{
	int		pipes[2];

	if (current == 0)
		tab->cmd[current].infile = 0;
	if (current + 1 < (int)tab->size)
    {
		if (pipe(pipes) == -1)
		{
			perror("pipe");
			tab->cmd->is_valid = false;
			return (*(tab->cmd));
		}
		tab->cmd[current].outfile = pipes[1];
		tab->cmd[current].outfile_is_pipe = true;
		tab->cmd[current + 1].infile = pipes[0];
		tab->cmd[current + 1].infile_is_pipe = true;
	}
    else
		tab->cmd[current].outfile = 1;
	return (tab->cmd[current]);
}

t_cmd		ft_init_cmd(char *token, t_env *env, t_tab_cmd *tab, int current)
{
	tab->cmd[current].args = ft_split(token, ' ');
	tab->cmd[current].function_name = ft_strdup(tab->cmd[current].args[0]);
	tab->cmd[current].is_build_in = is_built_in(tab->cmd[current].function_name);
	if (!tab->cmd[current].is_build_in)
		tab->cmd[current].path = ft_strdup(find_cmd_path(env, tab->cmd[current].function_name));
	else
		tab->cmd[current].path = ft_strdup(tab->cmd[current].function_name);
	tab->cmd[current].is_valid = true;
	if (tab->cmd[current].is_build_in == false && !tab->cmd[current].path)
		tab->cmd[current].is_valid = false;
	if (!tab->cmd[current].path)
		tab->cmd[current].path = ft_strdup(tab->cmd[current].function_name);
	ft_init_cmd_is_pipe(tab, current);
	current++;
	return (tab->cmd[current]);
}

t_tab_cmd	*ft_init_tab(char *line, t_env *env, int count_pipe)
{
	char		**tab_split;
	t_tab_cmd	*tab;
	int			i;

	i = 0;
	tab_split = ft_split(line, '|');
	tab = ft_calloc(1, sizeof(t_tab_cmd));
	tab->size = count_pipe + 1;
	tab->cmd = ft_calloc(count_pipe + 2, sizeof(t_cmd));
	while ((size_t)i < tab->size)
	{
		ft_init_cmd(tab_split[i], env, tab, i);
		if (tab->cmd[i].is_valid == false)
		{
			break ;
		}
		i++;
	}
	free_tab(tab_split);
	return (tab);
}

