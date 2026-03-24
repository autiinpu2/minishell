/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 05:48:25 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/24 04:03:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include <errno.h>

typedef struct s_exec
{
	bool	exist;
	bool	is_built_in;
	int		exit_code;
	bool	should_exit;
}				t_exec;

int		exec(t_data	*data);
int		wait_all_pids(t_data *data);

void	add_new_env_node(t_data *data, char *arg);
void	change_env_value(t_data *data, char *key, char *new_value);

void	duplicate_fds(int in, int out, int *saved_in, int *saved_out);
void	duplicate_outfile(int in, int out, int *saved_out);
void	restore_fds(int saved_in, int saved_out);
void	restore_fd(int saved, int set);
int		ft_env(t_data *data, t_cmd cmd);
int		ft_pwd(t_data *data, t_cmd cmd);
void	ft_cd(t_data *data, t_cmd cmd);
int		ft_exit( t_data *data, t_cmd cmd);
int		ft_unset(t_data *data, t_cmd cmd);
int		ft_export(t_data *data, t_cmd cmd);
void	sort_envp(char **envp, size_t len);
void	print_export(t_env *env);
char	**export_split(char *arg, t_data *data);
int		ft_echo(t_cmd cmd);

void	run_forks(t_cmd cmd, t_data *data, int id);
void	call_chdir(char *path, t_data *data);
int		run_built_in(t_cmd cmd, t_data *data);
void	run_built_in_fork(t_data *data, t_cmd cmd);
void	err(t_cmd cmd, t_data *data);
void	close_every_pipe(t_cmd *cmd, int id);
void	check_pipes_errors(t_cmd cmd);

#endif
