/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 03:32:53 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/15 09:05:22 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "exec.h"
#include "free.h"
#include "libft.h"
#include "minishell.h"

#include "minishell.h"

/* Returns the full path to the history file. Protected against NULL HOME. */
static char	*get_hist_path(t_data *data)
{
	char	*home;

	home = get_env_from_name("HOME", data->env);
	if (!home)
		return (NULL);
	return (ft_strjoin(home, "/.minishell_history"));
}

/* Iterates through the buffer, replacing \n with \0 to add lines to history. */
static void	parse_history_buffer(char *buf)
{
	char	*s;
	char	*nl;

	s = buf;
	while (s && *s)
	{
		nl = ft_strchr(s, '\n');
		if (nl)
			*nl = '\0';
		if (*s)
			add_history(s);
		if (nl)
			s = nl + 1;
		else
			break ;
	}
}

/* Reads the entire history file into a dynamically allocated string. */
void	load_history(t_data *data)
{
	int		fd;
	char	*path;
	char	*buf;
	int		sz;

	path = get_hist_path(data);
	if (!path)
		return ;
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
		return ;
	sz = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buf = ft_calloc(sz + 1, sizeof(char));
	if (buf && read(fd, buf, sz) > 0)
		parse_history_buffer(buf);
	free(buf);
	close(fd);
}

void	ft_add_history(char *line, t_data *data)
{
	int		fd;
	char	*path;

	if (!line || !*line)
		return ;
	path = get_hist_path(data);
	if (!path)
		return ;
	fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0600);
	free(path);
	if (fd < 0)
		return ;
	ft_putendl_fd(line, fd);
	close(fd);
	add_history(line);
}
