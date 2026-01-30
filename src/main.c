/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/30 03:57:08 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "exec.h"

t_tab_cmd   *fake_cmd()
{
	t_tab_cmd   *tab;
	t_cmd       *cmds;
	int         pipe_fds[2];

	tab = ft_calloc(1, sizeof(t_tab_cmd));
	cmds = ft_calloc(3, sizeof(t_cmd));
	
	if (pipe(pipe_fds) == -1)
		return (perror("pipe"), NULL);

	cmds[0].function_name = ft_strdup("ls");
	cmds[0].path = ft_strdup("/usr/bin/ls");
	cmds[0].args = ft_calloc(3, sizeof(char *));
	cmds[0].args[0] = ft_strdup("ls");
	cmds[0].args[1] = ft_strdup("-l");
	cmds[0].args[2] = NULL;
	cmds[0].infile = STDIN_FILENO;
	cmds[0].outfile = pipe_fds[1];
	cmds[0].outfile_is_pipe = true;

	cmds[1].function_name = ft_strdup("cat");
	cmds[1].path = ft_strdup("/usr/bin/cat");
	cmds[1].args = ft_calloc(2, sizeof(char *));
	cmds[1].args[0] = ft_strdup("cat"); 
	cmds[1].args[1] = NULL;
	cmds[1].infile = pipe_fds[0];
	cmds[1].infile_is_pipe = true;
	cmds[1].outfile = open("test_files/output_files", O_CREAT | O_WRONLY | O_APPEND, 0664);
	
	tab->size = 3;
	tab->cmd = cmds;
	return (tab);
}

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
		// tab = parsing(env, line);
		tab = fake_cmd();
		if (*line)
			add_history(line);
		if (!ft_strcmp(line, "exit"))
		{
			exit_code = 1;
			break ;
		}
		exit_code = exec(env, tab, exit_code);
		free(line);
		free(prefix);
	}
	free_double(line, prefix);
	free_env(env);
	return (exit_code);
}
