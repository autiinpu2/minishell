/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 02:11:16 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/14 07:47:37 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	duplicate_fds(int in, int out, int *saved_in, int *saved_out)
{
	*saved_in = dup(STDIN_FILENO);
	*saved_out = dup(STDOUT_FILENO);
	dup2(in, STDIN_FILENO);
	if (in > 2)
		close(in);
	dup2(out, STDOUT_FILENO);
	if (out > 2)
		close(out);
}

void	duplicate_outfile(int in, int out, int *saved_out)
{
	*saved_out = dup(STDOUT_FILENO);
	dup2(out, STDOUT_FILENO);
	if (out > 2)
		close(out);
	if (in > 2)
		close(in);
}

void	restore_fd(int saved, int set)
{
	dup2(saved, set);
	close(saved);
}

void	restore_fds(int saved_in, int saved_out)
{
	restore_fd(saved_in, STDIN_FILENO);
	restore_fd(saved_out, STDOUT_FILENO);
}
