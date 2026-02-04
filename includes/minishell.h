/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:01:53 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/04 00:52:28 by mcomin           ###   ########.fr       */
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
    int		type;// 1">"" 2">>"" 3"<" 4"<<"
    char	*file;
}   		t_redir;

typedef struct s_cmd
{
    char	**args;
	char	*function_name;
	char	*path;
    t_redir	*redirs;
	int		infile;
	int		outfile;
    int		redir_count;
	bool	is_built_in;
    int     pid;
}   		t_cmd;

typedef struct s_data
{
    t_cmd	*cmds;
    size_t		size;
	t_env	*env;
    int		last_exit;
	
}   		t_data;

t_data	*parsing(t_env *env, char *line);
t_data	*ft_init_data(char *input, t_env *env);
bool	is_built_in(char *name);

#endif
