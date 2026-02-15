/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:31:00 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/15 15:54:59 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "exec.h"
#include "free.h"

char	*load_file_content(char *path)
{
	int		fd;
	int		bytes_read;
	char	buffer[4097];
	char	*content;

	if (!path)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 4096);
		if (bytes_read == -1)
		{
			free(content);
			break ;
		}
		buffer[bytes_read] = '\0';
		content = ft_strjoin_free(content, buffer);
	}
	close(fd);
	return (content);
}

int	add_mark(t_data *data, t_cmd cmd)
{
	char	cwd[1024];
	char	*path;
	int		fd;

	if (!getcwd(cwd, sizeof(cwd)))
		return (1);
	path = get_path(data, "/.minishell_marks");
	fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 0644);
	free(path);
	if (fd < 0)
		return (1);
	ft_putstr_fd(cmd.args[2], fd);
	ft_putstr_fd("=", fd);
	ft_putstr_fd(cwd, fd);
	ft_putstr_fd("\n", fd);
	close(fd);
	return (0);
}

int	function(char *content, t_data *data, t_cmd cmd)
{
	int		i;
	char	**lines;
	char	**pair;

	lines = ft_split(content, '\n');
	free(content);
	i = -1;
	while (lines && lines[++i])
	{
		pair = ft_split(lines[i], '=');
		if (pair && pair[0] && pair[1] && ft_strcmp(pair[0], cmd.args[1]) == 0)
		{
			call_chdir(pair[1], data);
			free_tab(pair);
			free_tab(lines);
			return (0);
		}
		free_tab(pair);
	}
	free_tab(lines);
	return (1);
}

int	go_to_mark(t_data *data, t_cmd cmd)
{
	char	*path;
	char	*content;
	int		err;

	path = get_path(data, "/.minishell_marks");
	content = load_file_content(path);
	free(path);
	if (!content)
	{
		ft_dprintf(2, "mark: no marks saved yet\n");
		return (1);
	}
	err = function(content, data, cmd);
	if (err == 1)
		ft_dprintf(2, "mark: %s: mark not found\n", cmd.args[1]);
	return (err);
}

int	ft_mark(t_data *data, t_cmd cmd)
{
	int	arg_count;

	arg_count = get_args_number(cmd.args);
	if (arg_count < 2)
	{
		ft_dprintf(2, "Usage: mark <name> OR mark add <name>\n");
		return (1);
	}
	if (arg_count == 3 && ft_strcmp(cmd.args[1], "add") == 0)
	{
		return (add_mark(data, cmd));
	}
	if (arg_count == 2)
	{
		return (go_to_mark(data, cmd));
	}
	ft_dprintf(2, "mark: too many arguments\n");
	return (1);
}
