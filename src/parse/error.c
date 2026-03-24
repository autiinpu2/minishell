/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:46:10 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/24 06:28:48 by apuyane          ###   ########.fr       */
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
		return (i - 1);
	return (0);
}

int	check_pipes(char *input)
{
	int	i;

	i = 0;
	while (ft_isspace(input[i]))
		i++;
	if (input[i] == '|')
		return (-1);
	i = 0;
	while (input[i])
	{
		if (input[i] == '|' && !is_in_quotes(input, i))
		{
			i++;
			while (input[i] && ft_isspace(input[i]))
				i++;
			if (input[i] == '|' || !input[i])
				return (i);
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
			i += check_count_redir(input + i);
			if (i == -1)
				return (-1);
			while (input[i] && ft_isspace(input[i]))
				i++;
			if (!input[i] || (input[i] == '>' || input[i] == '<')
				|| input[i] == '|')
				return (i);
		}
		else
			i++;
	}
	return (0);
}

int	check_syntax(char *input)
{
	int	i;
	int	j;
	int	k;
	int	id;

	i = check_quotes(input);
	j = check_pipes(input);
	k = check_redirections(input);
	if (i || j || k)
	{
		if (i > 0 || j > 0 || k > 0)
		{
			id = 2147483647;
			if (i > 0 && i < id)
				id = i;
			if (j > 0 && j < id)
				id = j;
			if (k > 0 && k < id)
				id = k;
			ft_dprintf(2, "minishell: syntax error near `%c'\n", input[id]);
		}
		return (1);
	}
	return (0);
}
