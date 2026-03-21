/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:46:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/21 06:33:54 by apuyane          ###   ########.fr       */
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

char	*expand_variable(char *line, t_data *data, int *j)
{
	int		reminder;
	char	*str;

	str = line;
	if (str[*j] == '$' && str[*j + 1]
		&& (ft_isalpha(str[*j + 1]) || str[*j + 1] == '_'
			|| str[*j + 1] == '?') && get_quote_state(str, *j) != 1)
	{
		reminder = *j + 1;
		(*j)++;
		if (str[reminder] != '?')
			skip_chars(str, j);
		str = get_expanded_string(str, reminder,
				*j + 1, data);
		*j = reminder - 2;
	}
	else if (str[*j] == '~' && get_quote_state(str, *j) == 0)
	{
		reminder = *j + 1;
		(*j)++;
		str = get_expanded_home(str, reminder, *j, data);
		*j = reminder - 2;
	}
	return (str);
}

void	expand(char **line, t_data *data)
{
	int	j;

	j = 0;
	if (!line || !*line)
		return ;
	while ((*line)[j])
	{
		if ((*line)[j] == '$' && (*line)[j + 1] &&
			((*line)[j + 1] == '\"' || (*line)[j + 1] == '\'') &&
				get_quote_state(*line, j) == 0)
			*line = remove_char_i(*line, j);
		else if (((*line)[j] == '$' && (*line)[j + 1] && (*line)[j + 1] != ' '
			&& (*line)[j + 1] != '\"' && get_quote_state(*line, j) != 1)
				|| (*line)[j] == '~')
			*line = expand_variable(*line, data, &j);
		j++;
	}
}
