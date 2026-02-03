/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:02:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/31 09:48:47 by apuyane          ###   ########.fr       */
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

void	ft_cd(t_built_in *built, int i)
{
	int	args_len;
	char	*tmp;

	args_len = get_args_number(built->tab->cmd[i].args);
	if (args_len > 2)
	{
		ft_dprintf(2, "cd: too many arguments");
		built->exit_code = 1;
		return ;
	}
	if (args_len == 1)
	{
		chdir(get_env_from_name("HOME", built->env));
		change_env_value(built->env, "OLDPWD", get_env_from_name("PWD", built->env));
		change_env_value(built->env, "PWD", get_env_from_name("HOME", built->env));
		built->exit_code = 0;
		return ;
	}
	if (!ft_strcmp(built->tab->cmd[i].args[1], "-"))
	{
		chdir(get_env_from_name("OLDPWD", built->env));
		tmp = ft_strdup(get_env_from_name("OLDPWD", built->env));
		change_env_value(built->env, "OLDPWD", get_env_from_name("PWD", built->env));
		change_env_value(built->env, "PWD", tmp);
		built->exit_code = 0;
		return ;
	}
	chdir(built->tab->cmd[i].args[1]);
	tmp = getcwd(NULL, 0);
	change_env_value(built->env, "OLDPWD", get_env_from_name("PWD", built->env));
	change_env_value(built->env, "PWD", tmp);
	built->exit_code = 0;
}
