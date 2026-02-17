/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:46:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/17 03:57:09 by apuyane          ###   ########.fr       */
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

void	expand_variable(char **tab_split, t_data *data, int *j)
{
	int		reminder;
	char	*str;

	str = *tab_split;
	if (str[*j] == '$' && str[*j + 1]
		&& (ft_isalpha(str[*j + 1]) || str[*j + 1] == '_'
			|| str[*j + 1] == '?') && get_quote_state(str, *j) != 1)
	{
		reminder = *j + 1;
		(*j)++;
		if (str[reminder] != '?')
			skip_chars(str, j);
		*tab_split = get_expanded_string(str, reminder,
				*j + 1, data);
		*j = -1;
	}
	else if (str[*j] && str[*j] == '~')
	{
		reminder = *j + 1;
		(*j)++;
		*tab_split = get_expanded_home(str, reminder,
				*j, data);
		*j = -1;
	}
}

// void	expand(char **tab_split, t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (tab_split[i])
// 	{
// 		j = 0;
// 		while (tab_split[i])
// 		{
// 			if (tab_split[i][j] == '$' && (tab_split[i][j + 1] == '\"'
// 				|| tab_split[i][j + 1] == '\'')
// 				&& get_quote_state(tab_split[i], j) == 0)
// 			{
// 				tab_split[i] = remove_char_i(tab_split[i], j);
// 				continue ;
// 			}
// 			expand_variable(&tab_split[i], data, &j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	expand(char **line, t_data *data)
{
	int	j;

	j = 0;
	while ((*line)[j])
	{
		if ((*line)[j] == '$' && ((*line)[j + 1] == '\"'
			|| (*line)[j + 1] == '\'') && get_quote_state(*line, j) == 0)
		{
			(*line) = remove_char_i((*line), j);
			continue ;
		}
		expand_variable(line, data, &j);
		j++;
	}
}
