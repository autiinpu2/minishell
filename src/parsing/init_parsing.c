/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:35:09 by mcomin            #+#    #+#             */
/*   Updated: 2026/01/30 03:46:12 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"

t_tab_cmd	*ft_init_tab(char *line)
{
	char		**tab_split;
	t_tab_cmd	*tab;
	//t_cmd		*cmd;
	int			i;
	int			len;

	i = 0;
	tab_split = ft_split(line, '|');
	while(tab_split[i])
		i++;
	len = i;
	i = 0;
	tab = ft_calloc(1, sizeof(t_tab_cmd));
	tab->size = len;
	tab->cmd = ft_calloc(len, sizeof(t_cmd));
	// tab->cmd[i];
	return (tab);
}

