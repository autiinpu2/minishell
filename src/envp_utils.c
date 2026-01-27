/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 06:09:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/27 05:20:51 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"

static t_env	*fill_env(t_env *env, char **envp)
{
	int			i;
	int			j;
	t_env_node	*node;
	t_env_node	*last;

	i = 0;
	while (envp[i])
	{
		node = ft_calloc(1, sizeof(t_env_node));
		j = 0;
		while (envp[i][j] != '=')
			j++;
		node->key = ft_substr(envp[i], 0, j);
		node->value = ft_strdup(envp[i] + j + 1);
		node->text = ft_strdup(envp[i]);
		if (!env->top)
			env->top = node;
		else
			last->next = node;
		last = node;
		i++;
	}
	env->size = i;
	return (env);
}

t_env	*load_envp(char **envp)
{
	int			i;
	t_env		*env;

	i = 0;
	while (envp[i])
		i++;
	env = ft_calloc(1, sizeof(t_env));
	env = fill_env(env, envp);
	env->size = i;
	return (env);
}

void	print_env(t_env *env)
{
	t_env_node	*node;

	node = env->top;
	while (node)
	{
		printf("%s=%s\n", node->key, node->value);
		node = node->next;
	}
}

char	*get_env_from_name(char *name, t_env *env)
{
	t_env_node	*node;

	node = env->top;
	while (node)
	{
		if (!ft_strcmp(node->key, name))
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
