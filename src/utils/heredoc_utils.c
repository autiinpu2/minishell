/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 00:52:23 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/21 23:06:42 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "free.h"

char *get_rand_numbers(int n)
{
	int		rand_fd;
	char	*rand_num;
	int		bytes_read;

	rand_fd = open("/dev/urandom", O_RDONLY);
	if (rand_fd < 0)
		return (NULL);
	rand_num = ft_calloc(n + 1, sizeof(char));
	while (1)
	{
		bytes_read = read(rand_fd, rand_num, n * sizeof(char));
		if (bytes_read <= 0)
			break ;
		if (ft_isalnum_string(rand_num) && ft_strlen(rand_num) == n)
			break ;
	}
	close(rand_fd);
	return (rand_num);
}

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
			break ;
		if (!ft_strcmp(line, delimiter))
			break ;
		ft_dprintf(cmd.infile, "%s\n", line);
		free_single(line);
	}
	free_single(line);
	close(cmd.infile);
}
