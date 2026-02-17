/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 06:09:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/17 08:18:09 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "free.h"
#include "exec.h"
#include "minishell.h"

t_env	*change_env_value(t_data *data, char *key, char *new_value)
{
	t_env_node	*node;
	char		*new_val;

	node = data->env->top;
	while (node)
	{
		if (!ft_strcmp(node->key, key))
		{
			free_double(node->value, node->text);
			node->value = ft_strdup(new_value);
			node->text = ft_strdup(node->key);
			node->text = ft_strjoin_free(node->text, "=");
			node->text = ft_strjoin_free(node->text, new_value);
			return (data->env);
		}
		node = node->next;
	}
	new_val = ft_strjoin(key, "=");
	new_val = ft_strjoin_free(new_val, new_value);
	add_new_env_node(data, new_val);
	free_single(new_val);
	return (data->env);
}

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
	if (!env)
		return (NULL);
	env = fill_env(env, envp);
	env->size = i;
	return (env);
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

char	**env_to_envp(t_env *env)
{
	t_env_node	*node;
	char		**envp;
	int			i;

	i = 0;
	envp = ft_calloc(env->size + 1, sizeof(char *));
	if (!envp)
		return NULL;
	node = env->top;
	while (i < env->size)
	{
		envp[i] = ft_strdup(node->text);
		node = node->next;
		i++;
	}
	return (envp);
}
