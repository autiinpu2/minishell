/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:26:31 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/15 15:40:28 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "exec.h"

bool	is_built_in(char *name)
{
	if (!ft_strcmp(name, "env"))
		return (true);
	else if (!ft_strcmp(name, "pwd"))
		return (true);
	else if (!ft_strcmp(name, "cd"))
		return (true);
	else if (!ft_strcmp(name, "exit"))
		return (true);
	else if (!ft_strcmp(name, "unset"))
		return (true);
	else if (!ft_strcmp(name, "export"))
		return (true);
	else if (!ft_strcmp(name, "echo"))
		return (true);
	else if (!ft_strcmp(name, "mark"))
		return (true);
	else
		return (false);
}

int	get_args_number(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

void	call_chdir(char *path, t_data *data)
{
	char	*tmp;

	if (chdir(path) == -1)
	{
		ft_dprintf(2, "cd: %s: %s\n", path, strerror(errno));
		data->exit_code = 1;
		return ;
	}
	else
	{
		tmp = getcwd(NULL, 0);
		change_env_value(data, "OLDPWD",
			get_env_from_name("PWD", data->env));
		change_env_value(data, "PWD", tmp);
		data->exit_code = 0;
		free(tmp);
		return ;
	}
}
