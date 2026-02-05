/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:02:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/05 11:13:12 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "free.h"

int	call_chdir(char *path)
{
	if (chdir(path) == -1)
	{
		ft_dprintf(2, "cd: %s: %s\n", path,  strerror(errno));
		return (1);
	}
	else
		return 0;
}

int	ft_cd(t_data *data, t_cmd cmd)
{
	int	args_len;
	char	*tmp;
	int		exit_code;

	args_len = get_args_number(cmd.args);
	if (args_len > 2)
	{
		ft_dprintf(2, "cd: too many arguments");
		return (1);
	}
	else if (args_len == 1)
	{
		exit_code = call_chdir(get_env_from_name("HOME", data->env));
		change_env_value(data->env, "OLDPWD", get_env_from_name("PWD", data->env));
		change_env_value(data->env, "PWD", get_env_from_name("HOME", data->env));
		return (exit_code);
	}
	else if (!ft_strcmp(cmd.args[1], "-"))
	{
		exit_code = call_chdir(get_env_from_name("OLDPWD", data->env));
		tmp = ft_strdup(get_env_from_name("OLDPWD", data->env));
		change_env_value(data->env, "OLDPWD", get_env_from_name("PWD", data->env));
		change_env_value(data->env, "PWD", tmp);
		return (exit_code);
	}
	exit_code = call_chdir(cmd.args[1]);
	tmp = getcwd(NULL, 0);
	change_env_value(data->env, "OLDPWD", get_env_from_name("PWD", data->env));
	change_env_value(data->env, "PWD", tmp);
	free_single(tmp);
	return (exit_code);
}
