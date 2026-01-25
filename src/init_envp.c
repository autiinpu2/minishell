/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 06:09:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/25 06:10:11 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/env.h"

t_env *load_envp(char **envp)
{
	int i;
	int	j;
	t_env	*env;
	t_env_node	*node;
	t_env_node	*last;
	
	i = 0;
	while (envp[i])
		i++;
	env = ft_calloc(1, sizeof(t_env));
	i = 0;
	while (envp[i])
	{
		node = ft_calloc(1, sizeof(t_env_node));
		j = 0;
		while(envp[i][j] != '=')
			j++;
		node->key = ft_substr(envp[i], 0, j);
		node->value = ft_strdup(envp[i] + j + 1);
		if (!env->top)
			env->top = node;
		else
			last->next = node;
		
		last = node;
		i++;
		
	}
	env->size = i;
	return env;
}

void	print_env(t_env *env)
{
	t_env_node *node;

	node = env->top;
	while (node)
	{
		printf("%s=%s\n", node->key, node->value);
		node = node->next;
	}
}
