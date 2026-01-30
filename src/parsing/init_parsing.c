/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:35:09 by mcomin            #+#    #+#             */
/*   Updated: 2026/01/30 08:04:23 by mcomin           ###   ########.fr       */
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
	tab->cmd[current].function_name = tab->cmd->args[0];
	tab->cmd[current].path = find_cmd_path(env, tab->cmd->function_name);
	tab->cmd[current].is_build_in = is_built_in(tab->cmd->function_name);
	tab->cmd[current].is_valid = true;
	ft_init_cmd_is_pipe(tab, current);
	current++;
	return (tab->cmd[current]);
}

t_tab_cmd	*ft_init_tab(char *line, t_env *env)
{
	char		**tab_split;
	t_tab_cmd	*tab;
	int			i;
	int			len;

	i = 0;
	tab_split = ft_split(line, '|');
	while(tab_split[i])
		i++;
	len = i;
	i = 0;
	tab = ft_calloc(1, sizeof(t_tab_cmd));
	tab->size = len;
	tab->cmd = ft_calloc(len, sizeof(t_cmd));
	while (i < len)
	{
		tab->cmd[i] = ft_init_cmd(tab_split[i], env, tab, i);
		if (tab->cmd->is_valid == 1)
			free_tab_cmd(tab);
		i++;
	}
	return (tab);
}

