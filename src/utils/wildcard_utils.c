/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:50:06 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/21 03:34:46 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	new = ft_calloc((i + 2), sizeof(char *));
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

void	fill_dir(DIR *dir, char ***new_dir)
{
	struct dirent	*entry;
	int				i;
	char			**temp;

	i = 0;
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			return ;
		if (entry->d_name[0] == '.')
			continue ;
		i = 0;
		while ((*new_dir)[i])
			i++;
		temp = *new_dir;
		*new_dir = clone_charstar(temp);
		(*new_dir)[i] = ft_strdup(entry->d_name);
		(*new_dir)[i + 1] = NULL;
		free_single(temp);
	}
}

char	**add_dir(char *directory, char **old_dir)
{
	DIR				*dir;
	char			**new_dir;

	new_dir = old_dir;
	dir = opendir(directory);
	if (!dir)
	{
		perror("opendir");
		return (old_dir);
	}
	fill_dir(dir, &new_dir);
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

char	*get_matching(char *pattern, char **elements)
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
		free_single(line);
		line = ft_strdup(pattern);
	}
	return (line);
}
