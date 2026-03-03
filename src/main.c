/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/02/17 08:13:50 by apuyane          ###   ########.fr       */
=======
/*   Updated: 2026/02/19 03:56:31 by apuyane          ###   ########.fr       */
>>>>>>> redir
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "exec.h"
#include "free.h"

bool	is_invalid(char *line, t_data *data)
{
	if (is_empty_or_spaces(line) || check_syntax(line))
	{
		if (check_syntax(line))
			data->exit_code = 2;
<<<<<<< HEAD
		free_single(line);
		return (true);
=======
		return (1);
>>>>>>> redir
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
	if (*line)
		ft_add_history(line, data);
	expand(&line, data);
	if (!is_invalid(line, data))
	{
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
