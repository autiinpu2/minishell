/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:50:25 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/24 07:25:49 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "exec.h"
#include "free.h"

void	run_single_cmd(t_data *data, char *line)
{
	int	exit_code;

	if (is_invalid(line, data))
		return ;
	if (!parsing(data, line))
		data->exit_code = exec(data);
	free_cmds(data);
	free_single(line);
	exit_code = data->exit_code;
	if (data->exit)
	{
		free_data(data);
		exit(exit_code);
	}
}

static char	*remove_n(char *line)
{
	int		len;
	int		i;
	char	*s;

	i = 0;
	len = ft_strlen(line);
	s = ft_calloc(len, sizeof(char));
	if (!s)
	{
		free(line);
		return (NULL);
	}
	while (i + 1 < len)
	{
		s[i] = line[i];
		i++;
	}
	free_single(line);
	return (s);
}

void	minishellrc_run(t_data *data, int run_cmd)
{
	char	*line;
	bool	first_run;

	first_run = true;
	while (first_run || line)
	{
		first_run = false;
		line = get_next_line(run_cmd);
		if (!line)
			return ;
		line = remove_n(line);
		if (!line)
			return ;
		run_single_cmd(data, line);
	}
}

void	minishellrc(t_data *data)
{
	int		run_cmd;
	char	*path;

	path = get_path(data, "/.minishellrc");
	if (!path)
		return ;
	run_cmd = open(path, O_RDWR | O_CREAT, 0664);
	free_single(path);
	if (run_cmd < 0)
		return ;
	minishellrc_run(data, run_cmd);
	close(run_cmd);
}
