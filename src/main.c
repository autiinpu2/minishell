/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/05 08:43:44 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "exec.h"
#include "free.h"

int	main(int ac, char **av, char **envp)
{
	char		*prefix;
	char		*line;
	t_data		*data;

	(void)ac;
	(void)av;
	data = new_data(envp);
	while (true)
	{
		prefix = ft_strdup(get_env_from_name("PWD", data->env));
		prefix = ft_strjoin_free(prefix, ">");
		line = readline(prefix);
		if (!line)
		{
			ft_dprintf(2, "exit\n");
			data->exit_code = 0;
			break ;
		}
		if (*line)
			add_history(line);
		if (is_empty_or_spaces(line))
		{
			free_double(line, prefix);
			continue;
		}
		if (check_syntax(line))
		{
			data->exit_code = 2;
			free_double(line, prefix);
			continue;
		}
		if (!parsing(data, line))
			data->exit_code = exec(data);
		if (data->exit)
			break ;
		free_double(line, prefix);
	}
	free_data(data);
	free_double(line, prefix);
	free_env(data->env);
	return (data->exit_code);
}
