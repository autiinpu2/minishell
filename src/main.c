/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/10 02:29:25 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "exec.h"
#include "free.h"

static char	*get_prefix(t_data *data)
{
	char	*pwd;
	char	*prompt;

	pwd = get_env_from_name("PWD", data->env);
	prompt = ft_strjoin(pwd, "> ");
	return (prompt);
}

int	is_invalid(char *line, t_data *data, char *prefix)
{
	if (is_empty_or_spaces(line) || check_syntax(line))
	{
		if (check_syntax(line))
			data->exit_code = 2;
		free_double(line, prefix);
		return (1);
	}
	return (0);
}

void	loop(t_data *data)
{
	char	*line;
	char	*prefix;

	while (true)
	{
		prefix = get_prefix(data);
		line = readline(prefix);
		if (!line)
		{
			ft_dprintf(2, "exit\n");
			break ;
		}
		if (*line)
			add_history(line);
		if (is_invalid(line, data, prefix))
			continue ;
		if (!parsing(data, line))
			data->exit_code = exec(data);
		if (data->exit)
			break ;
		free_double(line, prefix);
	}
	free_double(line, prefix);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int		exit_code;

	(void)ac;
	(void)av;
	data = new_data(envp);
	loop(data);
	exit_code = data->exit_code;
	free_data(data);
	return (exit_code);
}
