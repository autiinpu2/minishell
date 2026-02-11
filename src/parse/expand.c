/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:46:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/11 08:17:43 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_exit_code(t_data *data, char *str_begin)
{
	char	*exit;
	char	*total;

	exit = ft_itoa(data->exit_code);
	total = ft_strjoin(str_begin, exit);
	free_single(exit);
	return (total);
}

static bool	is_in_single_quotes(char *string, size_t pos)
{
	size_t	i;
	int		single_quotes;

	i = 0;
	single_quotes = 0;
	while (i < pos)
	{
		if (string[i] == '\'')
			single_quotes = !single_quotes;
		i++;
	}
	return (single_quotes);
}

char	*get_expanded_string(char *string, int begin, int end, t_data *data)
{
	char	*str_begin;
	char	*str_end;
	char	*total;
	char	*var;

	if (is_in_single_quotes(string, begin))
		return (string);
	if (begin)
		str_begin = ft_substr(string, 0, begin - 1);
	else
		str_begin = ft_strdup("");
	var = ft_substr(string, begin, end - begin);
	if (!ft_strcmp(var, "?"))
		total = ft_exit_code(data, str_begin);
	else
		total = ft_strjoin(str_begin, get_env_from_name(var, data->env));
	str_end = ft_substr(string, end, ft_strlen(string));
	total = ft_strjoin_free(total, str_end);
	free_double(str_begin, var);
	free_double(str_end, string);
	return (total);
}

void	skip_chars(char **tab, int i, int *j)
{
	while (tab[i][*j] && (ft_isalnum(tab[i][*j])
		|| tab[i][*j] == '_'))
		(*j)++;
	(*j)--;
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
			if (tab_split[i][j] == '$' && tab_split[i][j + 1] != ' ' &&
				tab_split[i][j + 1])
			{
				j++;
				reminder = j;
				if (tab_split[i][reminder] != '?')
					skip_chars(tab_split, i, &j);
				tab_split[i] = get_expanded_string(tab_split[i], reminder,
						j + 1, data);
				j--;
			}
			j++;
		}
		i++;
	}
}
