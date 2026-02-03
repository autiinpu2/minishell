/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:26:31 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 11:13:03 by apuyane          ###   ########.fr       */
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
	else
		return (false);
}
