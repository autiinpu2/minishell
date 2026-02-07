/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:26:31 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/07 00:36:40 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

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

void	duplicate_fds(int in, int out, int *saved_in, int *saved_out)
{
	*saved_in = dup(STDIN_FILENO);
	*saved_out = dup(STDOUT_FILENO);
	if (in > 2)
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
	if (out > 2)
	{
		dup2(out, STDOUT_FILENO);
		close(out);
	}
}

void	restore_fds(int saved_in, int saved_out)
{
	dup2(saved_in, STDIN_FILENO);
	close(saved_in);
	dup2(saved_out, STDOUT_FILENO);
	close(saved_out);
}