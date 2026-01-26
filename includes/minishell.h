/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:16:51 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/27 00:44:03 by apuyane          ###   ########.fr       */
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
	bool			infile_is_pipe;
	char			*path;
	char			**args;
	int				outfile;
	bool			outfile_is_pipe;
	int				is_build_in;
	char			*function_name;
	pid_t			pid;
	struct s_cmd	*next;
}			t_cmd;

t_cmd	*parsing(t_env *env, char *line);

void	free_cmd(t_cmd *cmd);
void	free_env(t_env *env);

#endif
