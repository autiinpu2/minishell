/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:16:06 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/27 06:51:54 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"

void	free_env(t_env *env)
{
	t_env_node	*node;
	t_env_node	*tmp;
	
	node = env->top;
	while (node)
	{
		free(node->key);
		free(node->value);
		free(node->text);
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(env);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
}

void	free_tab_cmd(t_tab_cmd *cmd)
{
	int	i;
	
	i = 0;
	while ((size_t)i < cmd->size)
	{
		free_tab(cmd->tab[i].args);
		free(cmd->tab[i].args);
		free(cmd->tab[i].function_name);
		free(cmd->tab[i].path);
		i++;
	}
	free(cmd->tab);
	free(cmd);
}
