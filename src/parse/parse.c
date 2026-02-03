/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:11:37 by mcomin            #+#    #+#             */
/*   Updated: 2026/01/31 12:12:31 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

unsigned int	parse_pipe(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '|')
			count++;
		i++;
	}
	return (count);
}

char	*is_path_cmd(char *prefix_cmd_name, char **tab_paths)
{
	int		i;
	char	*test_path;

	i = 0;
	while (tab_paths[i])
	{
		test_path = ft_strjoin(tab_paths[i], prefix_cmd_name);
		if (access(test_path, X_OK) == 0)
			return (test_path);
		free(test_path);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(t_env *env, char *cmd_name)
{
	char	*prefix_cmd_name;
	char	*env_path;
	char	**tab_paths;
	char	*test_path;

	if (!cmd_name[0])
		return (NULL);
	if (access(cmd_name, X_OK) == 0)
		return (cmd_name);
	env_path = get_env_from_name("PATH", env);
	tab_paths = ft_split(env_path, ':');
	prefix_cmd_name = ft_strjoin("/", cmd_name);
	test_path = is_path_cmd(prefix_cmd_name, tab_paths);
	if (!test_path)
		test_path = ft_strdup("");
	free_tab(tab_paths);
	free(prefix_cmd_name);
	return (test_path);
}

t_tab_cmd	*parsing(t_env *env, char *line)
{
	t_tab_cmd	*tab;
	size_t	count_pipe;

	count_pipe = parse_pipe(line);
	tab = ft_init_tab(line, env, count_pipe);
	return (tab);
}
