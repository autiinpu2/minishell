/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 01:56:49 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/30 03:33:36 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**env_to_envp(t_env *env)
{
	t_env_node	*node;
	char		**envp;
	int			i;

	i = 0;
	envp = ft_calloc(env->size + 1, sizeof(char *));
	node = env->top;
	while (i < env->size)
	{
		envp[i] = ft_strdup(node->text);
		node = node->next;
		i++;
	}
	return (envp);
}

int	exec(t_env *env, t_tab_cmd *tab, int exit_code)
{
	char		**envp;
	t_built_in	*built_in;

	envp = env_to_envp(env);
	built_in = ft_calloc(1, sizeof(t_built_in));
	built_in->args = tab->cmd[0].args;
	built_in->exit_code = exit_code;
	built_in->env = env;
	create_processes(tab, envp, built_in);
	free_tab(envp);
	free_single(envp);
	free_single(built_in);
	close_all_fds(tab->cmd);
	exit_code = wait_all_pids(tab);
	return (exit_code);
}
