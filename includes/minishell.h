/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 05:21:42 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/13 03:34:47 by apuyane          ###   ########.fr       */
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

typedef struct s_redir
{
	int		type; // 1">"" 2">>"" 3"<" 4"<<"
	char	*file;
}				t_redir;

typedef struct s_cmd
{
	char	**args;
	char	*function_name;
	char	*path;
	t_redir	*redirs;
	int		redir_count;
	int		infile;
	int		outfile;
	bool	is_built_in;
	int		pid;
}			t_cmd;

typedef struct s_data
{
	t_cmd	*cmds;
	size_t	size;
	t_env	*env;
	int		exit_code;
	bool	exit;
}			t_data;

int		parsing(t_data *data, char *line);
t_data	*new_data(char **envp);
int		check_syntax(char *input);
int		is_empty_or_spaces(char *input);
bool	is_built_in(char *name);

int		get_args_number(char **args);

void	load_history(t_data *data);
void	add_historique(char *line, t_data *data);

#endif
