/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/26 08:22:18 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"
#include "../includes/libft.h"

t_cmd	*fake_cmd()
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	cmd->args = ft_calloc(1,1);
	cmd->function_name = ft_strdup("cat");
	cmd->infile = 0;
	cmd->is_build_in = 0;
	cmd->next = NULL;
	cmd->outfile = 1;
	cmd->path = ft_strdup("/usr/bin/cat");
	return (cmd);
}

int	main(int ac, char **av, char **envp)
{
	char	*prefix;
	char	*line;
	t_env	*env;
	t_cmd	*cmd;
	int		exit_code;

	(void)ac;
	(void)av;
	env = load_envp(envp);
	exit_code = EXIT_SUCCESS;
	// cmd = fake_cmd();
	while (true)
	{
		prefix = ft_strdup(get_env_from_name("PWD", env));
		prefix = ft_strjoin_free(prefix, ">");
		line = readline(prefix);
		// cmd = parsing(env, line);
		if (!ft_strcmp(line, "exit"))
		{
			exit_code = 1;
			break ;
		}
		// exec(cmd, env);
		free(line);
		free(prefix);
	}
	if (line)
		free(line);
	if (prefix)
		free(prefix);
	free_env(env);
	free_cmd(cmd);
	return (exit_code);
}
