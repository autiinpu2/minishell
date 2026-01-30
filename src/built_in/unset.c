/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 06:21:24 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/30 10:48:11 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_unset(t_env *env, char *unset)
{
	t_env_node	*node;
	t_env_node	*tmp;

	node = env->top;
	while (node)
	{
		if (!ft_strcmp(unset, node->key))
		{
			tmp = node->next;
			node->next = node->next->next;
			free(tmp);
			env->size -= 1;
			return ;
		}
		else if (node->next && !ft_strcmp(unset, node->next->key))
		{
			tmp = node->next;
			node->next = node->next->next;
			free(tmp);
			env->size -= 1;
			return ;
		}
		node = node->next;
	}
}
