/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:56:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/14 07:41:56 by apuyane          ###   ########.fr       */
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
	int			stdin;

	node = data->env->top;
	if (!node)
		return (1);
	duplicate_fds(cmd.infile, cmd.outfile, &stdin, &stdout);
	while (node)
	{
		ft_dprintf(1, "%s\n", node->text);
		node = node->next;
	}
	restore_fds(stdin, stdout);
	return (0);
}

int	ft_pwd(t_data *data, t_cmd cmd)
{
	int		stdout;
	int		stdin;
	int		exit_code;
	char	*pwd;

	pwd = NULL;
	exit_code = 0;
	if (!data->env)
		return (1);
	duplicate_fds(cmd.infile, cmd.outfile, &stdin, &stdout);
	pwd = get_env_from_name("PWD", data->env);
	if (pwd)
		ft_dprintf(1, "%s\n", pwd);
	else
		exit_code = 1;
	restore_fds(stdin, stdout);
	return (exit_code);
}

void	ft_exit_utils(t_data *data)
{
	if (data->size == 1)
	{
		data->exit = true;
		ft_dprintf(2, "exit\n");
	}
}

int	ft_exit(t_data *data, t_cmd cmd)
{
	int			num_args;
	long long	n;
	char		*endptr;

	num_args = get_args_number(cmd.args);
	ft_exit_utils(data);
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
		data->exit_code = 1;
		ft_dprintf(2, "exit: too many arguments\n");
	}
	return (data->exit_code);
}
