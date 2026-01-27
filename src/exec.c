/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 01:56:49 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/27 06:49:22 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"

char **env_to_envp(t_env *env)
{
	t_env_node	*node;
	char		**envp;
	int			i;

	i = 0;
	envp = ft_calloc(env->size, sizeof(char *));
	node = env->top;
	while (node)
	{
		envp[i] = node->text;
		node = node->next;
		i++;
	}
	return (envp);
}

void	exec(t_env *env)
{
	char	**envp;

	envp = env_to_envp(env);

	free_tab(envp);
}
