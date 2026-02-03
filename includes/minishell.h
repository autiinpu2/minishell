/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:01:53 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 07:29:33 by apuyane          ###   ########.fr       */
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
# include <limits.h>
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
	bool			is_valid;
}			t_cmd;

typedef struct s_tab_cmd
{
	size_t	size;
	t_cmd	*cmd;
	bool	is_valid;
}				t_tab_cmd;

t_tab_cmd	*parsing(t_env *env, char *line);
bool		is_built_in(char *name);

#endif
