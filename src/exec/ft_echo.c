/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 06:19:46 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/13 06:31:08 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "exec.h"

void	skip_flags(t_cmd cmd, int *i, int *n_flag)
{
	int	j;

	while (cmd.args[*i] && cmd.args[*i][0] == '-' && cmd.args[*i][1] == 'n')
	{
		j = 1;
		while (cmd.args[*i][j] == 'n')
			j++;
		if (cmd.args[*i][j] == '\0')
		{
			*n_flag = 1;
			(*i)++;
		}
		else
			break ;
	}
}

int	ft_echo(t_cmd cmd)
{
	int	i;
	int	n_flag;
	int	stdin_backup;
	int	stdout_backup;

	i = 1;
	n_flag = 0;
	duplicate_fds(cmd.infile, cmd.outfile, &stdin_backup, &stdout_backup);
	skip_flags(cmd, &i, &n_flag);
	while (cmd.args[i])
	{
		write(STDOUT_FILENO, cmd.args[i], ft_strlen(cmd.args[i]));
		if (cmd.args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (!n_flag)
		write(STDOUT_FILENO, "\n", 1);
	restore_fds(stdin_backup, stdout_backup);
	return (0);
}
