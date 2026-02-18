/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 04:34:29 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/18 03:36:52 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "free.h"

void	add_cmds(char **tab, char **new_tab, int *j)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (is_redir(tab[i]) == 1)
		{
			i++;
			if (tab[i])
				i++;
		}
		else
		{
			new_tab[*j] = ft_strdup(tab[i]);
			i++;
			(*j)++;
		}
	}
}

char	**swap(char **tab)
{
	char	**new_tab;
	int		len;
	int		i;
	int		j;

	len = 0;
	j = 0;
	while (tab[len])
		len++;
	new_tab = ft_calloc(len + 1, sizeof(char *));
	add_cmds(tab, new_tab, &j);
	i = 0;
	while (tab[i])
	{
		if (is_redir(tab[i]) == 1)
		{
			new_tab[j++] = ft_strdup(tab[i++]);
			if (tab[i])
				new_tab[j++] = ft_strdup(tab[i++]);
		}
		else
			i++;
	}
	free_tab(tab);
	return (new_tab);
}

void	redir_swap(char ***tab)
{
	int	i;

	i = 0;
	*tab = swap(*tab);
}
