/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/28 08:15:05 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "exec.h"

int	main(int ac, char **av, char **envp)
{
	char		*prefix;
	char		*line;
	t_env		*env;
	t_tab_cmd	*cmd;
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
		// cmd = parsing(env, line);
		cmd = fake_cmd();
		exit_code = exec(env, cmd, exit_code);
		free_tab_cmd(cmd);
		free_double(line, prefix);
	}
	free_double(line, prefix);
	free_env(env);
	return (exit_code);
}
