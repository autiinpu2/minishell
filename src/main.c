/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/27 06:51:22 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"

t_tab_cmd	*fake_cmd()
{
	t_tab_cmd	*tab;
	t_cmd	*cmd;

	tab = ft_calloc(1, sizeof(t_tab_cmd));
	cmd = ft_calloc(1, sizeof(t_cmd));
	cmd->function_name = ft_strdup("cat");
	cmd->infile = 0;
	cmd->args = ft_calloc(1, sizeof(char *));
	cmd->args[0] = NULL;
	cmd->is_build_in = 0;
	cmd->outfile = 1;
	cmd->path = ft_strdup("/usr/bin/cat");
	tab->size = 1;
	tab->tab = cmd;
	return (tab);
}

int	main(int ac, char **av, char **envp)
{
	char	*prefix;
	char	*line;
	t_env	*env;
	t_tab_cmd	*cmd;
	int		exit_code;

	(void)ac;
	(void)av;
	env = load_envp(envp);
	exit_code = EXIT_SUCCESS;
	cmd = fake_cmd();
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
		free(line);
		free(prefix);
	}
	if (line)
		free(line);
	if (prefix)
		free(prefix);
	free_env(env);
	free_tab_cmd(cmd);
	return (exit_code);
}
