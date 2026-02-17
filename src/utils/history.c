/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 03:32:53 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/17 08:14:58 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "exec.h"
#include "free.h"
#include "libft.h"
#include "minishell.h"

static char	*find_last_line(char *buf, int size)
{
	int		i;
	int		start;
	char	*last;

	if (size <= 0)
		return (NULL);
	i = size - 1;
	if (buf[i] == '\n')
		i--;
	while (i >= 0 && buf[i] != '\n')
		i--;
	start = i + 1;
	last = ft_substr(buf, start, size - start - (buf[size - 1] == '\n'));
	return (last);
}

char	*get_last_line(char *path)
{
	int			fd;
	char		*buf;
	char		*last;
	struct stat	st;

	if (stat(path, &st) == -1 || st.st_size == 0)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (st.st_size + 1));
	if (!buf)
	{
		close(fd);
		return (NULL);
	}
	if (read(fd, buf, st.st_size) <= 0)
	{
		free(buf);
		close(fd);
		return (NULL);
	}
	buf[st.st_size] = '\0';
	last = find_last_line(buf, st.st_size);
	free(buf);
	close(fd);
	return (last);
}

void	ft_add_history(char *line, t_data *data)
{
	char	*path;
	char	*last;
	int		fd;

	if (!line || !*line)
		return ;
	path = get_path(data, "/.minishell_history");
	last = get_last_line(path);
	if ((!last || ft_strcmp(line, last)) || !path)
	{
		add_history(line);
		if (path)
		{
			fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
			if (fd >= 0)
			{
				ft_putendl_fd(line, fd);
				close(fd);
			}
		}
	}
	free(path);
	free(last);
}
