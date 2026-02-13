/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:46:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/13 06:38:39 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	skip_chars(char **tab, int i, int *j)
{
	if (tab[i][*j] && (ft_isalnum(tab[i][*j]) || tab[i][*j] == '_'))
	{
		while (tab[i][*j] && (ft_isalnum(tab[i][*j]) || tab[i][*j] == '_'))
			(*j)++;
		(*j)--;
	}
}

void	expand(char **tab_split, t_data *data)
{
	int	i;
	int	j;
	int	reminder;

	i = 0;
	while (tab_split[i])
	{
		j = 0;
		while (tab_split[i][j])
		{
			if (tab_split[i][j] == '$' && (tab_split[i][j + 1] == '\"'
				|| tab_split[i][j + 1] == '\'')
				&& get_quote_state(tab_split[i], j) == 0)
			{
				tab_split[i] = remove_char_i(tab_split[i], j);
				continue ;
			}
			if (tab_split[i][j] == '$' && tab_split[i][j + 1] &&
				(ft_isalpha(tab_split[i][j + 1])
				|| tab_split[i][j + 1] == '_' ||
				tab_split[i][j + 1] == '?') &&
				get_quote_state(tab_split[i], j) != 1)
			{
				reminder = j + 1;
				j++;
				if (tab_split[i][reminder] != '?')
					skip_chars(tab_split, i, &j);
				tab_split[i] = get_expanded_string(tab_split[i], reminder,
						j + 1, data);
				j = -1;
			}
			j++;
		}
		i++;
	}
}
