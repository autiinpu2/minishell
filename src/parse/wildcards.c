/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:41:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/20 01:42:46 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "minishell.h"
#include "parsing.h"

char	**clone_charstar(char **old)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (old && old[i])
		i++;
	new = malloc((i + 2) * sizeof(char *));
	if (!new)
		return (NULL);
	while (j < i)
	{
		new[j] = old[j];
		j++;
	}
	new[j] = NULL;
	new[j + 1] = NULL;
	return (new);
}

char	**add_dir(char *directory, char **old_dir)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**new_dir;
	char			**temp;
	int				i;

	i = 0;
	new_dir = old_dir;
	dir = opendir(directory);
	if (dir == NULL)
	{
		perror("opendir");
		return (old_dir);
	}
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_name[0] == '.')
			continue ;
		i = 0;
		while (new_dir[i])
			i++;
		temp = new_dir;
		new_dir = clone_charstar(temp);
		new_dir[i] = strdup(entry->d_name);
		new_dir[i + 1] = NULL;
		free(temp);
	}
	closedir(dir);
	return (new_dir);
}

int	strmatch(char *pattern, char *name)
{
	if (!*pattern && !*name)
		return (1);
	if (*pattern == '*')
		return (strmatch(pattern + 1, name)
			|| (*name && strmatch(pattern, name + 1)));
	if (*pattern == *name)
		return (strmatch(pattern + 1, name + 1));
	return (0);
}

char	*print_matching(char *pattern, char **elements)
{
	int		i;
	int		found;
	char	*line;

	i = 0;
	found = 0;
	line = ft_strdup("");
	while (elements[i])
	{
		if (strmatch(pattern, elements[i]))
		{
			line = ft_strjoin_free(line, elements[i]);
			line = ft_strjoin_free(line, " ");
			found = 1;
		}
		i++;
	}
	if (found == 0)
	{
		free(line);
		line = ft_strdup(pattern);
	}
	return (line);
}

int	ft_strcmp_case(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	i = 0;
	while (s1b[i] && s2b[i] && ft_tolower(s1b[i]) == ft_tolower(s2b[i]))
		i++;
	return (ft_tolower(s1b[i]) - ft_tolower(s2b[i]));
}

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

char *find_files(char *expr, char *folder)
{
	char	**elements;
	char	*line;

	elements = malloc(sizeof(char *));
	elements[0] = NULL;
	elements = add_dir(folder, elements);
	sort(elements);
	line = print_matching(expr, elements);
	return line;
}

int count_files(char *directory)
{
	DIR *dir;
	struct dirent *entry;
	int count;

	dir = opendir(directory);
	count = 0;
	if (!dir) return -1;
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] != '.')
			count++;
	}
	closedir(dir);
	return count;
}

char **open_folder(char *directory)
{
	DIR *dir;
	struct dirent *entry;
	char **file_list;
	int count;
	int i;

	count = count_files(directory);
	if (count == -1)
		return NULL;
	file_list = malloc((count + 1) * sizeof(char *));
	if (!file_list)
		return (NULL);
	dir = opendir(directory);
	i = 0;
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.')
			continue;
		file_list[i++] = strdup(entry->d_name);
	}
	file_list[i] = NULL;
	closedir(dir);
	return (file_list);
}

char	*wildcard(char *expr)
{
	char *line;
	char	*new_expr;
	char	**tab;
	int	i;
	
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
