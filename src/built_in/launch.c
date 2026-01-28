/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:38:04 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/28 08:17:57 by apuyane          ###   ########.fr       */
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

void	run_built_in(char *function, t_built_in *built)
{
	if (!ft_strcmp(function, "exit"))
		built_in_exit(built);
	if (!ft_strcmp(function, "env"))
		print_env(built->env);
}
