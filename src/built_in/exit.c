/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:14:30 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/31 12:15:50 by apuyane          ###   ########.fr       */
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

void	ft_exit(t_built_in *built_in, int i)
{
	int	num_args;
	int	exit_code;

	num_args = get_args_number(built_in->args);
	exit_code = built_in->exit_code;
	if (num_args > 2)
	{
		ft_dprintf(2, "%s", "exit: too many arguments\n");
		built_in->exit_code = 1;
		return ;
	}
	else if (num_args == 1)
	{
		ft_dprintf(2, "%s", "exit\n");
		free_tab_cmd(built_in->tab);
		free_env(built_in->env);
		free_tab(built_in->envp);
		free(built_in);
		exit(0);
	}
	else
	{
		ft_dprintf(2, "%s", "exit\n");
		if (ft_contain_digit_only(built_in->tab->cmd[i].args[1]))
			exit_code = ft_atoi(built_in->tab->cmd[i].args[1]);
		else
		{
			exit_code = 2;
			ft_dprintf(2, "exit: %s: numeric argument required\n", built_in->tab->cmd[i].args[1]);
		}
		free_tab_cmd(built_in->tab);
		free_env(built_in->env);
		free_tab(built_in->envp);
		free(built_in);
		exit(exit_code);
	}
}
