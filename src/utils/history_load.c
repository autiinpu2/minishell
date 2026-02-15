/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:46:29 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/15 10:47:46 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "exec.h"
#include "free.h"
#include "libft.h"
#include "minishell.h"

static char	*get_hist_path(t_data *data)
{
	char	*home;

	home = get_env_from_name("HOME", data->env);
	if (!home)
		return (NULL);
	return (ft_strjoin(home, "/.minishell_history"));
}

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

void	load_history(t_data *data)
{
	int			fd;
	char		*path;
	char		*buf;
	struct stat	st;

	path = get_hist_path(data);
	if (!path)
		return ;
	if (stat(path, &st) == -1 || st.st_size <= 0)
	{
		free(path);
		return ;
	}
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
		return ;
	buf = ft_calloc(st.st_size + 1, sizeof(char));
	if (buf && read(fd, buf, st.st_size) > 0)
		parse_history_buffer(buf);
	free(buf);
	close(fd);
}
