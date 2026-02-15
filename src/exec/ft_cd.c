/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:02:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/15 21:09:43 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "free.h"

static void	special_case(char *name, t_data *data)
{
	if (!ft_strcmp(name, "-"))
	{
		call_chdir(get_env_from_name("OLDPWD", data->env), data);
		return ;
	}
	else if (!ft_strcmp(name, "~"))
	{
		call_chdir(get_env_from_name("HOME", data->env), data);
		return ;
	}
}

static bool	is_special(char *name)
{
	return ((!ft_strcmp(name, "-") || !ft_strcmp(name, "~")));
}

void	ft_cd(t_data *data, t_cmd cmd)
{
	int		args_len;

	args_len = get_args_number(cmd.args);
	if (args_len > 2)
	{
		ft_dprintf(2, "minishell: cd: too many arguments");
		data->exit_code = 1;
	}
	else if (args_len == 1)
	{
		call_chdir(get_env_from_name("HOME", data->env), data);
	}
	else if (is_special(cmd.args[1]))
	{
		special_case(cmd.args[1], data);
	}
	else
		call_chdir(cmd.args[1], data);
}
