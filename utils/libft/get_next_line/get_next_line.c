/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:28:34 by aubin             #+#    #+#             */
/*   Updated: 2026/01/25 04:51:03 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fd_protect(int fd, char **buff)
{
	if (fd > 1024 || fd < 0 || BUFFER_SIZE <= 0 || !buff || !*buff)
	{
		free(*buff);
		return (0);
	}
	return (1);
}

static int	handle_error(int bytes_read, char **text, char **buff)
{
	if (bytes_read < 0)
	{
		free(*text);
		*text = NULL;
		free(*buff);
		return (-1);
	}
	if (bytes_read == 0)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*buff;
	char		*line;
	int			bytes_read;
	int			error;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!fd_protect(fd, &buff))
		return (NULL);
	bytes_read = BUFFER_SIZE;
	while (!find_nl(text) && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		error = handle_error(bytes_read, &text, &buff);
		if (error == -1)
			return (NULL);
		else if (error == 0)
			break ;
		buff[bytes_read] = '\0';
		text = ft_strjoin(text, buff);
	}
	free(buff);
	line = extract_line(text);
	text = save_rest(text);
	return (line);
}
