/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:16:06 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/04 00:41:59 by mcomin           ###   ########.fr       */
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
		tab[i] = NULL;
		i++;
	}
	free_single(tab);
}

void	free_data(t_data *data)
{
	size_t	i;
	
	i = 0;
	while (i < data->size)
	{
		if (data->cmds[i].infile > 2)
			close(data->cmds[i].infile);
		free_tab(data->cmds[i].args);
		free_single(data->cmds[i].function_name);
		free_single(data->cmds[i].path);
		i++;
	}
	free_single(data->cmds);
	free_single(data);
}

void	free_single(void *s)
{
	if (s)
		free(s);
	s = NULL;
}

void	free_double(void *s1, void *s2)
{
	if (s1)
		free(s1);
	s1 = NULL;
	if (s2)
		free(s2);
	s2 = NULL;
}