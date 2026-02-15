/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:51:56 by aubin             #+#    #+#             */
/*   Updated: 2026/02/15 02:07:17 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char *text)
{
	int		i;
	char	*line;

	if (!text || !*text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	line = malloc((i + (text[i] == '\n') + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	free_and_return(char *ptr)
{
	if (!ptr || !*ptr)
	{
		free(ptr);
		return (0);
	}
	return (1);
}

char	*save_rest(char *text)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (!free_and_return(text))
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		i++;
	rest = malloc(ft_strlen(text) - i + 1);
	if (!rest)
	{
		free(text);
		return (NULL);
	}
	while (text[i])
		rest[j++] = text[i++];
	rest[j] = '\0';
	free(text);
	return (rest);
}
