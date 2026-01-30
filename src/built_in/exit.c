/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:14:30 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/30 10:42:19 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	get_args_number(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

void	ft_exit(t_built_in *built_in)
{
	int	num_args;
	int	exit_code;

	num_args = get_args_number(built_in->args);
	exit_code = built_in->exit_code;
	if (num_args > 2)
		ft_dprintf(2, "%s", "exit: too many arguments\n");
	else if (num_args == 1)
	{
		ft_dprintf(2, "%s", "exit\n");
		free_tab_cmd(built_in->tab);
		free_env(built_in->env);
		free_tab(built_in->envp);
		free(built_in);
		exit(exit_code);
	}
	else
	{
		ft_dprintf(2, "%s", "exit\n");
		exit_code = ft_atoi(built_in->args[1]);
		exit(exit_code);
	}
}
