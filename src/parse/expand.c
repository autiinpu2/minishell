/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:46:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/14 05:02:28 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	skip_chars(char *tab, int *j)
{
	if (tab[*j] && (ft_isalnum(tab[*j]) || tab[*j] == '_'))
	{
		while (tab[*j] && (ft_isalnum(tab[*j]) || tab[*j] == '_'))
			(*j)++;
		(*j)--;
	}
}

void	second_if(char *tab_split, t_data *data, int *j)
{
	int	reminder;

	if (tab_split[*j] == '$' && tab_split[*j + 1]
		&& (ft_isalpha(tab_split[*j + 1]) || tab_split[*j + 1] == '_'
			|| tab_split[*j + 1] == '?') && get_quote_state(tab_split, *j) != 1)
	{
		reminder = *j + 1;
		(*j)++;
		if (tab_split[reminder] != '?')
			skip_chars(tab_split, j);
		tab_split = get_expanded_string(tab_split, reminder,
				*j + 1, data);
		*j = -1;
	}
}

void	expand(char **tab_split, t_data *data)
{
	int	i;
	int	j;

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
			second_if(tab_split[i], data, &j);
			j++;
		}
		i++;
	}
}
