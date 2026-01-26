/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:16:06 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/26 08:16:21 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"
#include "../includes/libft.h"

void	free_env(t_env *env)
{
	t_env_node	*node;
	t_env_node	*tmp;
	
	node = env->top;
	while (node)
	{
		free(node->key);
		free(node->value);
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(env);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*node;
	t_cmd	*tmp;
	
	node = cmd;
	while (node)
	{
		free(node->args);
		free(node->function_name);
		free(node->path);
		tmp = node->next;
		free(node);
		node = tmp;
	}
}
