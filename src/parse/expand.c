/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:46:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/11 05:50:54 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_expanded_string(char *string, int begin, int end, t_data *data)
{
	char	*str_begin;
	char	*str_end;
	char	*total;
	char	*var;

	if (begin)
		str_begin = ft_substr(string, 0, begin - 1);
	else
		str_begin = ft_strdup("");
	var = ft_substr(string, begin, end - begin);
	if (!ft_strcmp(var, "?"))
		total = ft_strjoin(str_begin, ft_itoa(data->exit_code));
	else
		total = ft_strjoin(str_begin, get_env_from_name(var, data->env));
	str_end = ft_substr(string, end + 1, ft_strlen(string));
	total = ft_strjoin_free(total, str_end);
	free_double(str_begin, var);
	free_single(str_end);
	free_single(string);
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
			if (tab_split[i][j] == '$' && tab_split[i][j + 1] != ' ')
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
