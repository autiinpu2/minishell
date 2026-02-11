/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:11:37 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/11 03:02:05 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		count_quotes_closed(char *str)
{
	char	type_quotes;
	int		quotes;
	int		i;

	i = 0;
	quotes = 0;
	while(str[i])
	{
		if(str[i] != '\'' && str[i] != '\"')
		{
			type_quotes = str[i];
			quotes = !quotes;
		}
		
	}
}

char	*supp_quotes_ext(char *str)
{
	char	*res;
	int		j;
	int		i;
	char	type_quote;
	
	i = 0;
	j = 0;
	type_quote = 0;
	while(str[i] && (str[i] != '\'' && str[i] != '\"'))
		i++;
	type_quote = str[i];
	i = 0;
	res = ft_calloc(ft_strlen(str) - 2 + 1, sizeof(char));
	while(str[i])
	{
		if (str[i] == type_quote)
			i++;
		if(!str[i])
			break;
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	handle_token(t_data *data)
{
	size_t	i;
	size_t	y;
	char 	*tmp;

	i = 0;
	y = 1;
	while (i < data->size)
	{
		while(data->cmds[i].args[y])
		{
			if (strchr(data->cmds[i].args[y], '\'')
				|| (strchr(data->cmds[i].args[y], '\"')))
			{
				tmp = supp_quotes_ext(data->cmds[i].args[y]);
				free(data->cmds[i].args[y]);
				data->cmds[i].args[y] = NULL;
				data->cmds[i].args[y] = ft_strdup(tmp);
				free(tmp);
				tmp = NULL;
			}
			y++;
		}
		i++;
	}		
}	

int	parsing(t_data *data, char *input)
{
	load_data(data, input);
	handle_token(data);
	return (0);
}
