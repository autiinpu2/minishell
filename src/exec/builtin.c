/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:56:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/05 05:28:46 by apuyane          ###   ########.fr       */
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
	close(stdout);
	return (0);
}

int	ft_pwd(t_env *env, t_cmd cmd)
{
	int         stdout_backup;
	int			exit_code;
	char		*pwd;

	pwd = NULL;
	exit_code = 0;
	if (!env)
		return (1);
	stdout_backup = dup(STDOUT_FILENO);
	dup2(cmd.outfile, STDOUT_FILENO);
	pwd = get_env_from_name("PWD", env);
	if (pwd)
		printf("%s\n", pwd);
	else
		exit_code = 1;
	dup2(stdout_backup, STDOUT_FILENO);
	close(stdout_backup);
	return (exit_code);
}

int	ft_exit(t_cmd cmd)
{
	int	num_args;
	int	exit_code;

	num_args = get_args_number(cmd.args);
	exit_code = 0;
	ft_dprintf(2, "exit\n");
	if (num_args == 1)
	{
		exit(exit_code);
	}
	else if (num_args == 2)
	{
		exit_code = ft_atoi(cmd.args[1]);
		exit(exit_code);
	}
	else
	{
		exit_code = 1;
		ft_dprintf(2, "exit: too many arguments\n");
	}
	return (exit_code);
}
