/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 07:33:49 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/10 02:16:03 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "free.h"

static void	remove_env_node(t_env *env, char *key)
{
	t_env_node	*curr;
	t_env_node	*prev;

	curr = env->top;
	prev = NULL;
	while (curr)
	{
		if (!ft_strcmp(curr->key, key))
		{
			if (prev)
				prev->next = curr->next;
			else
				env->top = curr->next;
			free_double(curr->key, curr->value);
			free_double(curr->text, curr);
			env->size -= 1;
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

int	ft_unset(t_data *data, t_cmd cmd)
{
	int	stdout_cpy;
	int	i;

	duplicate_outfile(cmd.infile, cmd.outfile, &stdout_cpy);
	if (data->size != 1)
	{
		restore_fd(stdout_cpy, STDOUT_FILENO);
		return (1);
	}
	i = 1;
	while (cmd.args && cmd.args[i])
	{
		remove_env_node(data->env, cmd.args[i]);
		i++;
	}
	restore_fd(stdout_cpy, STDOUT_FILENO);
	return (0);
}
