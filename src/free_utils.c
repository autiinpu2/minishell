/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:16:06 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/28 07:32:39 by apuyane          ###   ########.fr       */
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
		free_single(node->key);
		free_single(node->value);
		free_single(node->text);
		tmp = node->next;
		free_single(node);
		node = tmp;
	}
	free(env);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free_single(tab[i]);
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
		if (cmd->tab[i].infile > 2)
			close(cmd->tab[i].infile);
		free_tab(cmd->tab[i].args);
		free_single(cmd->tab[i].args);
		free_single(cmd->tab[i].function_name);
		free_single(cmd->tab[i].path);
		i++;
	}
	free_single(cmd->tab);
	free_single(cmd);
}

void	free_single(void *s)
{
	if (s)
		free(s);
}

void	free_double(void *s1, void *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}
