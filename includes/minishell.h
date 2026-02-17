/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 05:21:42 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/17 01:02:04 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "env.h"

extern int	g_signal_status;

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
	int		access;
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
int		is_invalid(char *line, t_data *data);

int		get_args_number(char **args);

void	load_history(t_data *data);
void	ft_add_history(char *line, t_data *data);

void	minishellrc(t_data *data);

void	signals(t_data *data);

int		ft_mark(t_data *data, t_cmd cmd);
char	*get_prefix(t_data *data);
char	*get_path(t_data *data, char *file);

#endif
