/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:46:10 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/24 04:44:12 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_empty_or_spaces(char *input)
{
	int	i;

	i = 0;
	if (!input[i])
		return (1);
	else if (ft_isspace(input[i]))
	{
		while (ft_isspace(input[i]))
			i++;
		if (input[i] == '\0')
			return (1);
	}
	return (0);
}

int	check_quotes(char *input)
{
	int		i;
	char	quotes;

	i = 0;
	quotes = '\0';
	while (input[i])
	{
		if (input[i] == '\'' && !quotes)
			quotes = input[i];
		else if (input[i] == '\'' && quotes == '\'')
			quotes = '\0';
		else if (input[i] == '\"' && !quotes)
			quotes = input[i];
		else if (input[i] == '\"' && quotes == '\"')
			quotes = '\0';
		i++;
	}
	if (quotes)
		return (1);
	return (0);
}

int	check_pipes(char *input)
{
	int	i;

	i = 0;
	while (ft_isspace(input[i]))
		i++;
	if (input[i] == '|')
		return (1);
	i = 0;
	while (input[i])
	{
		if (input[i] == '|' && !is_in_quotes(input, i))
		{
			i++;
			while (input[i] && ft_isspace(input[i]))
				i++;
			if (input[i] == '|' || !input[i])
				return (1);
		}
		else
			i++;
	}
	return (0);
}

int	check_redirections(char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (!input[i])
			break ;
		if ((input[i] == '>' || input[i] == '<') && !is_in_quotes(input, i))
		{
			i = check_count_redir(input + i);
			if (i == -1)
				return (1);
			while (input[i] && ft_isspace(input[i]))
				i++;
			if (!input[i] || (input[i] == '>' || input[i] == '<')
				|| input[i] == '|')
				return (1);
		}
		else
			i++;
	}
	return (0);
}

int	check_syntax(char *input)
{
	if (check_quotes(input))
		return (1);
	if (check_pipes(input))
		return (1);
	if (check_redirections(input))
		return (1);
	return (0);
}
