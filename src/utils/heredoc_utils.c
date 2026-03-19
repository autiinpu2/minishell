/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 00:52:23 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/19 06:28:33 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	read_heredoc(char *delimiter, t_cmd cmd)
{
	char	*content;
	char	*line;

	content = ft_strdup("");
	while (1)
	{
		line = readline("heredoc>");
		if (!line)
			break ;
		if (!ft_strcmp(line, delimiter))
			break ;
		ft_putstr_fd(line, cmd.infile);
		ft_putstr_fd("\n", cmd.infile);
		free(line);
	}
	free(line);
	close(cmd.infile);
}
