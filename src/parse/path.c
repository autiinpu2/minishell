/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:35:21 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/11 08:53:23 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	check_access(char *path)
{
	struct stat	st;

	if (stat(path, &st) == 0)
	{
		if (S_ISDIR(st.st_mode))
			return (false);
		else if (S_ISREG(st.st_mode) && access(path, X_OK) == 0)
			return (true);
	}
	return (false);
}

int	count_pipe(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '|' && !is_in_quotes(input, i))
			count++;
		i++;
	}
	return (count);
}

char	*is_path(char *prefix_cmd_name, char **tab_paths)
{
	int		i;
	char	*test_path;

	i = 0;
	while (tab_paths[i])
	{
		test_path = ft_strjoin(tab_paths[i], prefix_cmd_name);
		if (check_access(test_path))
			return (test_path);
		free(test_path);
		i++;
	}
	return (NULL);
}

char	*cmd_path(t_env *env, char *cmd_name)
{
	char	*prefix_cmd_name;
	char	*env_path;
	char	**tab_paths;
	char	*test_path;

	if (!cmd_name[0])
		return (NULL);
	env_path = get_env_from_name("PATH", env);
	tab_paths = ft_split(env_path, ':');
	prefix_cmd_name = ft_strjoin("/", cmd_name);
	test_path = is_path(prefix_cmd_name, tab_paths);
	if (!test_path && check_access(cmd_name))
	{
		test_path = ft_strdup(cmd_name);
		return (test_path);
	}
	if (!test_path)
		test_path = ft_strdup("");
	free_tab(tab_paths);
	free(prefix_cmd_name);
	return (test_path);
}
