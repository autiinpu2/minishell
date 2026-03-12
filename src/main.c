/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/12 19:40:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "exec.h"
#include "free.h"
#include "parsing.h"

bool	is_invalid(char *line, t_data *data)
{
	if (is_empty_or_spaces(line) || check_syntax(line))
	{
		if (check_syntax(line))
			data->exit_code = 2;
		return (true);
	}
	return (false);
}

int	check_signal(t_data *data)
{
	if (g_signal_status != 0)
	{
		data->exit_code = 128 + g_signal_status;
		g_signal_status = 0;
		return (1);
	}
	return (0);
}

void	process_input(t_data *data, char *line)
{
	int		redir;
	char	*tmp;

	if (*line)
		ft_add_history(line, data);
	redir = count_redir_input(line);
	if (!is_invalid(line, data))
	{
		if (redir)
		{
			tmp = ft_strdup(line);
			free_single(line);
			line = reload_input_redir(tmp, redir);
			free(tmp);
		}
		if (!parsing(data, line))
			data->exit_code = exec(data);
	}
	free_single(line);
	free_cmds(data);
}

void	loop(t_data *data)
{
	char	*line;
	char	*prefix;

	while (!data->exit)
	{
		prefix = get_prefix(data);
		line = readline(prefix);
		free_single(prefix);
		if (check_signal(data) != 0)
			continue ;
		if (!line)
			break ;
		process_input(data, line);
	}
	rl_clear_history();
	if (!line)
		ft_dprintf(2, "exit\n");
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int		exit_code;

	(void)ac;
	(void)av;
	data = init_data(envp);
	if (!data)
		return (1);
	load_history(data);
	minishellrc(data);
	signals();
	loop(data);
	exit_code = data->exit_code;
	free_data(data);
	return (exit_code);
}
