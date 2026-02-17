/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/17 03:50:13 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "exec.h"
#include "free.h"

int	is_invalid(char *line, t_data *data)
{
	if (is_empty_or_spaces(line) || check_syntax(line))
	{
		if (check_syntax(line))
			data->exit_code = 2;
		free_single(line);
		return (1);
	}
	return (0);
}

int	check_signal(t_data *data)
{
	if (g_signal_status == SIGINT)
	{
		data->exit_code = 128 + SIGINT;
	}
	g_signal_status = 0;
	return (data->exit_code);
}

void	loop(t_data *data)
{
	char	*line;
	char	*prefix;

	while (true)
	{
		prefix = get_prefix(data);
		line = readline(prefix);
		free_single(prefix);
		data->exit_code = check_signal(data);
		if (!line)
		{
			ft_dprintf(2, "exit\n");
			return ;
		}
		if (*line)
			ft_add_history(line, data);
		expand(&line, data);
		if (is_invalid(line, data))
			continue ;
		if (!parsing(data, line))
			data->exit_code = exec(data);
		free_cmds(data);
		free_single(line);
		if (data->exit)
			return ;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int		exit_code;

	(void)ac;
	(void)av;
	data = new_data(envp);
	load_history(data);
	signals();
	minishellrc(data);
	loop(data);
	exit_code = data->exit_code;
	free_data(data);
	return (exit_code);
}
