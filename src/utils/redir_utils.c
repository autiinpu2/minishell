/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:47:14 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/19 03:39:39 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

bool	is_redir(char *arg)
{
	if (!arg || !*arg)
		return (false);
	if ((arg[0] == '>' && arg[1] == '>') || (arg[0] == '<' && arg[1] == '<'))
	{
		if (arg[2] == '>' || arg[2] == '<')
			return (false);
		return (true);
	}
	if (arg[0] == '>' || arg[0] == '<')
	{
		if (arg[1] == '>' || arg[1] == '<')
			return (false);
		return (true);
	}
	return (false);
}

int	is_in_tab(char **tab, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], str))
			count++;
		i++;
	}
	return (count);
}

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] && tab[i][0])
		i++;
	return (i + 1);
}
