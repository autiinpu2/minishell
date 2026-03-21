/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 00:52:23 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/21 05:02:42 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "free.h"

void	read_heredoc(char *delimiter, t_cmd cmd)
{
	char	*line;
	int		count;

	count = 0;
	while (++count)
	{
		line = readline("heredoc>");
		if (!line)
		{
			ft_dprintf(2, "minishell: warning: here-document at line %d "
				"delimited by end-of-file (wanted `%s')\n", count, delimiter);
			break ;
		}
		if (g_signal_status == SIGINT)
		{
			close(cmd.infile);
			return ;
		}
		if (!ft_strcmp(line, delimiter))
			break ;
		ft_dprintf(cmd.infile, "%s\n", line);
		free_single(line);
	}
	free_single(line);
	close(cmd.infile);
}
