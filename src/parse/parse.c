/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:11:37 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/11 08:52:01 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_quotes_closed(char *str)
{
	int		count;
	char	in_quote;

	count = 0;
	in_quote = 0;
	while (*str)
	{
		if (!in_quote && (*str == '\"' || *str == '\''))
		{
			in_quote = *str;
			count++;
		}
		else if (*str == in_quote)
		{
			in_quote = 0;
			count++;
		}
		str++;
	}
	return (count);
}

char	*supp_quotes(char *str)
{
	char	type_quote;
	char	*res;
	int		size;
	int		j;
	int		i;

	type_quote = 0;
	j = 0;
	i = -1;
	size = ft_strlen(str) - count_quotes_closed(str);
	res = ft_calloc(size + 1, sizeof(char));
	while (str[++i])
	{
		if (!type_quote && (str[i] == '\"' || str[i] == '\''))
			type_quote = str[i];
		else if (str[i] == type_quote)
			type_quote = 0;
		else
		{
			res[j] = str[i];
			j++;
		}
	}
	return (res);
}

void	handle_token(t_data *data)
{
	size_t	i;
	size_t	y;
	char	*tmp;

	i = 0;
	y = 0;
	while (i < data->size)
	{
		while (data->cmds[i].args[y])
		{
			if (strchr(data->cmds[i].args[y], '\'')
				|| (strchr(data->cmds[i].args[y], '\"')))
			{
				tmp = supp_quotes(data->cmds[i].args[y]);
				free_single(data->cmds[i].args[y]);
				data->cmds[i].args[y] = ft_strdup(tmp);
				free_single(tmp);
			}
			y++;
		}
		free_single(data->cmds[i].function_name);
		data->cmds[i].function_name = ft_strdup(data->cmds[i].args[0]);
		i++;
	}
}

int	parsing(t_data *data, char *input)
{
	load_data(data, input);
	handle_token(data);
	return (0);
}
