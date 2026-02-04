/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 05:48:25 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/04 00:39:01 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "minishell.h"

typedef struct s_exec
{
	bool	exist;
	bool	is_built_in;
	int		exit_code;
}				t_exec;

int	exec(t_env *env, t_data	*data);
int wait_all_pids(t_data *data, t_exec *exec);

int	ft_env(t_env *env, t_cmd cmd);

#endif