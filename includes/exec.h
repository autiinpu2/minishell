/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 05:48:25 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/07 00:36:55 by apuyane          ###   ########.fr       */
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

void	duplicate_fds(int in, int out, int *saved_in, int *saved_out);
void	restore_fds(int saved_in, int saved_out);
int		ft_env(t_data *data, t_cmd cmd);
int		ft_pwd(t_data *data, t_cmd cmd);
int		ft_cd(t_data *data, t_cmd cmd);
int		ft_exit( t_data *data, t_cmd cmd);
int		ft_unset(t_data *data, t_cmd cmd);
int		ft_export(t_data *data, t_cmd cmd);
int		ft_echo(t_data *data, t_cmd cmd);

void	run_forks(t_cmd cmd, t_data *data, int id);

#endif
