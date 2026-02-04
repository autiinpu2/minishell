/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 05:48:25 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/04 07:44:31 by apuyane          ###   ########.fr       */
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

int	exec(t_env *env, t_data	*data);
int wait_all_pids(t_data *data, t_exec *exec);

int	ft_env(t_env *env, t_cmd cmd);
int	ft_pwd(t_env *env, t_cmd cmd);
int	ft_cd(t_env *env, t_cmd cmd);
int	ft_exit(t_cmd cmd);
int	ft_unset(t_env *env, t_cmd cmd);
int	ft_export(t_env *env, t_cmd cmd);

#endif
