/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 01:55:48 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 01:01:53 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "env.h"
# include "libft.h"

# include <sys/wait.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <signal.h>


typedef struct s_built_in
{
	int			exit_code;
	char		**args;
	t_env		*env;
	t_tab_cmd	*tab;
	char		**envp;
}				t_built_in;

void	create_processes(t_tab_cmd *tab, char **envp);
int		wait_all_pids(t_tab_cmd *cmd);
void	close_all_fds(t_cmd *cmd);
void	close_every_pipe(t_tab_cmd *cmd, int i);
void	run_cmd(t_tab_cmd *cmd, char **envp, int i);

// built in
void	run_built_in(char *function, t_built_in *built, int i);
void	ft_exit(t_built_in *built_in, int i);
void	ft_pwd(t_env *env, t_built_in *built, int i);
void	ft_unset(t_env *env, char *unset);
void	print_env(t_env *env, t_built_in *built, int i);
void	ft_cd(t_built_in *built, int i);

#endif