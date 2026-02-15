/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:08:22 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/15 08:00:26 by apuyane          ###   ########.fr       */
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

void	err(t_cmd cmd, t_data *data)
{
	if (cmd.access == -1)
		exit(0);
	if (cmd.access == 1)
	{
		ft_dprintf(2, "%s: command not found\n", cmd.function_name);
		close_every_pipe(data->cmds, -1);
		free_data(data);
		exit(127);
	}
	else if (cmd.access == 2)
		ft_dprintf(2, "%s: Is a directory\n", cmd.function_name);
	else if (cmd.access == 3)
		ft_dprintf(2, "%s: Permission denied\n", cmd.function_name);
	if (cmd.access >= 2)
	{
		close_every_pipe(data->cmds, -1);
		free_data(data);
		exit(126);
	}
}

void	run_cmd(t_data *data, t_cmd cmd)
{
	char	**envp;

	err(cmd, data);
	envp = env_to_envp(data->env);
	check_pipes(cmd);
	dup2(cmd.infile, 0);
	dup2(cmd.outfile, 1);
	close_every_pipe(data->cmds, -1);
	execve(cmd.path, cmd.args, envp);
	perror("execve failed");
	free_data(data);
	exit(1);
}

void	run_forks(t_cmd cmd, t_data *data, int id)
{
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
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	run_cmd(data, cmd);
}
