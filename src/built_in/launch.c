/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:38:04 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/30 11:03:28 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

bool	is_built_in(char *name)
{
	int	i;

	i = 0;
	while (BUILT_INS[i])
	{
		if (!ft_strcmp(name, BUILT_INS[i]))
			return (true);
		i++;
	}
	return (false);
}

void	run_built_in(char *function, t_built_in *built, int i)
{
	if (!ft_strcmp(function, "exit"))
		ft_exit(built);
	else if (!ft_strcmp(function, "env"))
		print_env(built->env, built, i);
	else if (!ft_strcmp(function, "pwd"))
		ft_pwd(built->env, built, i);
	else if (!ft_strcmp(function, "unset"))
		ft_unset(built->env, built->args[1]);
}
