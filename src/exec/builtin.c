/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:56:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/06 17:14:07 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "exec.h"

int	ft_env(t_data *data, t_cmd cmd)
{
	t_env_node	*node;
	int			stdout;

	stdout = dup(STDOUT_FILENO);
	node = data->env->top;
	if (!node)
		return (1);
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
	dup2(stdout, STDOUT_FILENO);
	close(stdout);
	return (0);
}

int	ft_pwd(t_data *data, t_cmd cmd)
{
	int		stdout;
	int		exit_code;
	char	*pwd;

	pwd = NULL;
	exit_code = 0;
	if (!data->env)
		return (1);
	stdout = dup(STDOUT_FILENO);
	dup2(cmd.outfile, STDOUT_FILENO);
	pwd = get_env_from_name("PWD", data->env);
	if (pwd)
		printf("%s\n", pwd);
	else
		exit_code = 1;
	dup2(stdout, STDOUT_FILENO);
	close(stdout);
	return (exit_code);
}

int	ft_exit(t_data *data, t_cmd cmd)
{
	int			num_args;
	long long	n;
	char		*endptr;

	num_args = get_args_number(cmd.args);
	if (data->size == 1)
	{
		data->exit = true;
		ft_dprintf(2, "exit\n");
	}
	if (num_args == 1)
		data->exit_code = 0;
	else if (num_args == 2)
	{
		n = ft_strtoll(cmd.args[1], &endptr);
		if (*endptr != '\0' || n > LONG_MAX || n < LONG_MIN)
		{
			ft_dprintf(2, "exit: %s: numeric argument required\n", cmd.args[1]);
			n = 2;
		}
		data->exit_code = (int)(n % 256);
	}
	else
	{
		data->exit_code = 2;
		ft_dprintf(2, "exit: too many arguments\n");
	}
	return (data->exit_code);
}

int	ft_echo(t_data *data, t_cmd cmd)
{
	int		i;
	char	n;

	i = 1;
	if (!ft_strcmp(cmd.args[1], "-n\0"))
	{
		n = '\0';
		i++;
	}
	else
		n = '\n';
	while (cmd.args[i])
	{
		if (!ft_strcmp(cmd.args[1], "$?\0"))
			printf("%d", data->exit_code);
		else
			printf("%s", cmd.args[i]);
		if (cmd.args[i + 1])
			printf("%c", ' ');
		i++;
	}
	printf("%c", n);
	return (0);
}
