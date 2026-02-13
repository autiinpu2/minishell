/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 03:32:53 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/13 04:12:13 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "exec.h"
#include "free.h"
#include "libft.h"
#include "minishell.h"

char	*remove_n(char *line)
{
	int		i;
	char	*s;
	int		len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	s = ft_calloc((len + 1), sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = line[i];
		i++;
	}
	free(line);
	return (s);
}

void	load_history(t_data *data)
{
	int		fd;
	int		edited;
	char	*path;
	char	*line;

	edited = 0;
	path = ft_strjoin(get_env_from_name("HOME", data->env),
			"/.minishell_history");
	fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0600);
	while (!edited || line)
	{
		edited = 1;
		line = get_next_line(fd);
		line = remove_n(line);
		if (line)
			add_history(line);
		free(line);
	}
	free(path);
	close(fd);
}

void	ft_add_history(char *line, t_data *data)
{
	int		fd;
	char	*path;

	path = ft_strjoin(get_env_from_name("HOME", data->env),
			"/.minishell_history");
	fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0600);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	close(fd);
	add_history(line);
}
