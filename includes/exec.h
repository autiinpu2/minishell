/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 01:55:48 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/28 08:09:47 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "env.h"
# include "libft.h" 

typedef struct s_built_in
{
	int		exit_code;
	char	**args;
	t_env	*env;
}				t_built_in;

void	create_processes(t_tab_cmd *cmd, char **envp, t_built_in *built_in);
int		wait_all_pids(t_tab_cmd *cmd);
void	close_all_fds(t_cmd *cmd);
void	close_every_pipe(t_tab_cmd *cmd, int i);
void	run_cmd(t_tab_cmd *cmd, char **envp, int i);

// built in
bool	is_built_in(char *name);
void	run_built_in(char *function, t_built_in *built);
void	built_in_exit(t_built_in *built_in);

#endif