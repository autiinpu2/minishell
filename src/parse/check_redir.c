/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 02:59:44 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/10 07:45:21 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_redir_input(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if ((!is_in_quotes(input, i)) && (input[i] == '>' || input[i] == '<'))
		{
			i++;
			count++;
			if (input[i] == '>' || input[i] == '<')
				break ;
		}
		i++;
	}
	return (count);
}

char	*reload_input_redir(char *input, int redir)
{
	char	*new_input;
	int		i;
	int		j;

	new_input = ft_calloc(ft_strlen(input) + (redir * 2) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (input[i])
	{
		if ((!is_in_quotes(input, i)) && (input[i] == '>' || input[i] == '<'))
		{
			new_input[j++] = ' ';
			new_input[j++] = input[i];
			if (input[i + 1] == input[i])
				new_input[j++] = input[++i];
			new_input[j++] = ' ';
		}
		else
			new_input[j++] = input[i];
		i++;
	}
	return (new_input);
}
