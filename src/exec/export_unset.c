/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 07:33:49 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/05 07:20:02 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "free.h"

int	ft_unset(t_data *data, t_cmd cmd)
{
	t_env_node	*node;
	t_env_node	*tmp;

	node = data->env->top;
	tmp = node;
	while (node)
	{
		node = node->next;
		if (!ft_strcmp(node->key, cmd.args[1]))
		{
			tmp->next = node->next;
			free_double(node->key, node->value);
			free_single(node->text);
			return (0);
		}
		tmp = node;
	}
	return (0);
}

void	sort_envp(char **envp, size_t len)
{
	size_t	i;
	char	*tmp;
	
	i = 0;
	while (i + 1 < len)
	{
		if (ft_strcmp(envp[i], envp[i + 1]) > 0)
		{
			tmp = envp[i];
			envp[i] = envp[i + 1];
			envp[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	print_export(t_env *env)
{
	char	**envp;
	size_t 	len;
	size_t	i;
	
	i = 0;
	envp = env_to_envp(env);
	len = get_args_number(envp);
	sort_envp(envp, len);
	while (i < len)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

void	add_new_env_node(t_env *env, char *arg)
{
	char **args;
	t_env_node *node;

	node = env->top;
	while (node->next)
		node = node->next;
	args = ft_split(arg, '=');
	node->next = ft_calloc(1, sizeof(t_env_node));
	node = node->next;
	node->key = ft_strdup(args[0]);
	node->value = ft_strdup(args[1]);
	node->text = ft_strjoin(node->key, "=");
	node->text = ft_strjoin_free(node->text, node->value);
}

int	ft_export(t_data *data, t_cmd cmd)
{
	size_t	len_args;
	size_t	i;

	len_args = get_args_number(cmd.args);
	if (len_args == 1)
	{
		print_export(data->env);
		return 0;
	}
	i = 0;
	while (i < len_args - 1)
	{
		add_new_env_node(data->env, cmd.args[i + 1]);
		i++;
	}
	return (0);
}
