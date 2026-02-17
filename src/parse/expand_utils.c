/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 06:33:48 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/17 07:43:39 by apuyane          ###   ########.fr       */
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

int	get_quote_state(char *string, size_t pos)
{
	size_t	i;
	int		state;

	i = 0;
	state = 0;
	while (i < pos && string[i])
	{
		if (string[i] == '\'' && state != 2)
		{
			if (state == 1)
				state = 0;
			else
				state = 1;
		}
		else if (string[i] == '\"' && state != 1)
		{
			if (state == 2)
				state = 0;
			else
				state = 2;
		}
		i++;
	}
	return (state);
}

char	*get_expanded_home(char *string, int begin, int end, t_data *data)
{
	char	*str_begin;
	char	*str_end;
	char	*total;
	char	*var;

	if (get_quote_state(string, begin) == 1)
		return (string);
	if (begin)
		str_begin = ft_substr(string, 0, begin - 1);
	else
		str_begin = ft_strdup("");
	var = get_env_from_name("HOME", data->env);
	total = ft_strjoin(str_begin, var);
	str_end = ft_substr(string, end, ft_strlen(string));
	total = ft_strjoin_free(total, str_end);
	free_single(str_begin);
	free_double(str_end, string);
	return (total);
}

char	*get_expanded_string(char *string, int begin, int end, t_data *data)
{
	char	*str_begin;
	char	*str_end;
	char	*total;
	char	*var;

	if (get_quote_state(string, begin) == 1)
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

char	*remove_char_i(char *str, int index)
{
	char	*new_str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	new_str = ft_calloc(ft_strlen(str), sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (i != index)
			new_str[k++] = str[i];
		i++;
	}
	free(str);
	return (new_str);
}
