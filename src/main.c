/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/04 04:17:21 by mcomin           ###   ########.fr       */
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
	t_env		*env;
	t_data	*data;

	(void)ac;
	(void)av;
	env = load_envp(envp);
	while (true)
	{
		prefix = ft_strdup(get_env_from_name("PWD", env));
		prefix = ft_strjoin_free(prefix, ">");
		line = readline(prefix);
		if (!line)
			break ;
		data = parsing(env, line);
		if (*line)
			add_history(line);
		free_double(line, prefix);
		data->exit_code = exec(env, data);
		free_data(data);
	}
	free_double(line, prefix);
	free_env(env);
	return (data->exit_code);
}
