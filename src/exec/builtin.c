/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:56:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 23:54:34 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "exec.h"

int	ft_env(t_env *env, t_cmd cmd)
{
	t_env_node *node;
	int			stdin;
	int			stdout;
	
	stdin = dup(STDIN_FILENO);
	stdout = dup(STDOUT_FILENO);
	node = env->top;
	if (!node)
		return (1);
	dup2(cmd.infile, STDIN_FILENO);
	dup2(cmd.outfile, STDOUT_FILENO);
	if (cmd.infile > 2)
		close(cmd.infile);
	if (cmd.outfile > 2)
		close(cmd.outfile);
	while (node)
	{
		printf("%s\n", node->text);
		node = node->next;
	}
	dup2(stdin, STDIN_FILENO);
	dup2(stdout, STDOUT_FILENO);
	close(stdin);
	close(stdout);return 0 ;
	return (0);
}
