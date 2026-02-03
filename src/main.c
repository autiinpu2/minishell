/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 07:33:35 by apuyane          ###   ########.fr       */
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
	t_tab_cmd	*tab;
	int			exit_code;

	(void)ac;
	(void)av;
	env = load_envp(envp);
	exit_code = EXIT_SUCCESS;
	while (true)
	{
		prefix = ft_strdup(get_env_from_name("PWD", env));
		prefix = ft_strjoin_free(prefix, ">");
		line = readline(prefix);
		if (!line)
			break ;
		tab = parsing(env, line);
		if (*line)
			add_history(line);
		free_double(line, prefix);
		exit_code = exec(env, tab);
		free_tab_cmd(tab);
	}
	free_double(line, prefix);
	free_env(env);
	return (exit_code);
}
