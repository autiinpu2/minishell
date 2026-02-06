/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:08:22 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/06 22:10:21 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "exec.h"
#include "free.h"

void	close_every_pipe(t_cmd *cmd, int id)
{
	int	i;

	i = 0;
	while (cmd[i].function_name)
	{
		if (i != id)
		{
			if (cmd[i].infile > 2)
				close(cmd[i].infile);
			if (cmd[i].outfile > 2)
				close(cmd[i].outfile);
		}
		i++;
	}
}

static void	check_pipes(t_cmd cmd)
{
	if (cmd.infile == -1)
	{
		if (cmd.outfile != -1)
			close(cmd.outfile);
		exit(1);
	}
	if (cmd.outfile == -1)
	{
		if (cmd.infile != -1)
			close(cmd.infile);
		exit(1);
	}
}

void	run_cmd(t_data *data, t_cmd cmd)
{
	char	**envp;

	if (!cmd.path[0])
	{
		ft_dprintf(2, "%s: command not found\n", cmd.function_name);
		close_every_pipe(data->cmds, -1);
		exit(127);
	}
	envp = env_to_envp(data->env);
	check_pipes(cmd);
	dup2(cmd.infile, 0);
	dup2(cmd.outfile, 1);
	close_every_pipe(data->cmds, -1);
	execve(cmd.path, cmd.args, envp);
	perror("execve failed");
	exit(1);
}

void	run_forks(t_cmd cmd, t_data *data, int id)
{
	int	i;

	i = 0;
	data->cmds[id].pid = fork();
	if (data->cmds[id].pid < 0)
	{
		perror("fork");
		if (cmd.infile > 2)
			close(cmd.infile);
		if (cmd.outfile > 2)
			close(cmd.outfile);
		free_data(data);
		exit(1);
	}
	if (data->cmds[id].pid != 0)
	{
		if (cmd.infile > 2)
			close(cmd.infile);
		if (cmd.outfile > 2)
			close(cmd.outfile);
		return ;
	}
	run_cmd(data, cmd);
}
