/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:35:06 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/14 10:35:36 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

bool	env_exist(char *name, t_env *env)
{
	t_env_node	*node;

	node = env->top;
	while (node)
	{
		if (!ft_strcmp(node->key, name))
			return (true);
		node = node->next;
	}
	return (false);
}
