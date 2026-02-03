/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 01:56:49 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 00:59:42 by apuyane          ###   ########.fr       */
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

t_built_in *init_built_in(t_tab_cmd *tab, int exit_code, t_env *env, char **envp)
{
	t_built_in *built;
	int			i;

	i = 0;
	built = ft_calloc(tab->size + 1, sizeof(t_built_in));
	while ((size_t)i < tab->size)
	{
		if (!tab->cmd[i].is_valid)
			break ;
		built[0].args = tab->cmd[i].args;
		built->exit_code = exit_code;
		built->env = env;
		built->tab = tab;
		built->envp = envp;
		i++;
	}
	if ((size_t)i == tab->size)
		return (built);
	return (NULL);
}

int	exec(t_env *env, t_tab_cmd *tab, int exit_code)
{
	char		**envp;
	t_built_in	*built_in;

	envp = env_to_envp(env);
	built_in = init_built_in(tab, exit_code, env, envp);
	create_processes(tab, envp);
	free_tab(envp);
	free_single(built_in);
	close_all_fds(tab->cmd);
	exit_code = wait_all_pids(tab);
	return (exit_code);
}
