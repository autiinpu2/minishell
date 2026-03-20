/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:41:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/20 02:08:03 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "parsing.h"

void	sort(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	if (!tab || !tab[0])
		return ;
	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp_case(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

char	*find_files(char *expr, char *folder)
{
	char	**elements;
	char	*line;

	elements = malloc(sizeof(char *));
	elements[0] = NULL;
	elements = add_dir(folder, elements);
	sort(elements);
	line = get_matching(expr, elements);
	return (line);
}

int	count_files(char *directory)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	dir = opendir(directory);
	count = 0;
	if (!dir)
		return (-1);
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_name[0] != '.')
			count++;
	}
	closedir(dir);
	return (count);
}

char	**open_folder(char *directory)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**file_list;
	int				count;
	int				i;

	count = count_files(directory);
	if (count == -1)
		return (NULL);
	file_list = ft_calloc(count + 1, sizeof(char *));
	if (!file_list)
		return (NULL);
	dir = opendir(directory);
	i = 0;
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_name[0] == '.')
			continue ;
		file_list[i++] = strdup(entry->d_name);
	}
	closedir(dir);
	return (file_list);
}

char	*wildcard(char *expr)
{
	char	*line;
	char	*new_expr;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(expr, ' ');
	line = ft_strdup("");
	while (tab[i])
	{
		new_expr = find_files(tab[i], ".");
		line = ft_strjoin_free(line, new_expr);
		line = ft_strjoin_free(line, " ");
		i++;
	}
	free(expr);
	return (line);
}
