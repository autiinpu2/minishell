/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:50:25 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/17 01:10:50 by apuyane          ###   ########.fr       */
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
	while (i + 1 < len)
	{
		s[i] = line[i];
		i++;
	}
	free(line);
	return (s);
}

void	minishellrc_run(t_data *data, int run_cmd)
{
	char	*line;
	bool	first_run;

	first_run = true;
	line = "";
	while (line || first_run)
	{
		if (first_run)
			first_run = false;
		line = get_next_line(run_cmd);
		if (!line)
			return ;
		line = remove_n(line);
		run_single_cmd(data, line);
	}
}

void	minishellrc(t_data *data)
{
	int		run_cmd;
	char	*path;

	path = get_path(data, "/.minishellrc");
	run_cmd = open(path, O_RDWR | O_CREAT, 0664);
	free(path);
	if (run_cmd < 0)
		return ;
	minishellrc_run(data, run_cmd);
	close(run_cmd);
}
