/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:16:51 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/27 06:40:18 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include "env.h"

typedef struct s_cmd
{
	int				infile;
	int				outfile;
	bool			infile_is_pipe;
	bool			outfile_is_pipe;
	char			*function_name;
	bool			is_build_in;
	char			*path;
	char			**args;
	pid_t			pid;
}			t_cmd;

typedef struct s_tab_cmd {
	size_t	size;
	t_cmd	*cmd;
}				t_tab_cmd;

t_cmd	*parsing(t_env *env, char *line);

void	free_tab_cmd(t_tab_cmd *cmd);
void	free_env(t_env *env);
void	free_tab(char **tab);

#endif
