/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:16:06 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/10 02:37:57 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "free.h"
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
		i++;
	}
	free_single(tab);
}

void	free_cmds(t_data *data)
{
	int	i;

	i = 0;
	while (i < (int)data->size)
	{
		if (data->cmds[i].infile > 2)
			close(data->cmds[i].infile);
		if (data->cmds[i].outfile > 2)
			close(data->cmds[i].outfile);
		free_tab(data->cmds[i].args);
		free_single(data->cmds[i].function_name);
		free_single(data->cmds[i].path);
		i++;
	}
	free_single(data->cmds);
}

void	free_data(t_data *data)
{
	free_cmds(data);
	free_env(data->env);
	free_single(data);
}
