/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:35:21 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/15 09:12:33 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_access(char *path, t_cmd *cmd)
{
	struct stat	st;

	if (stat(path, &st) == 0)
	{
		if (S_ISDIR(st.st_mode))
		{
			cmd->access = 2;
			return (2);
		}
		else if (S_ISREG(st.st_mode) && access(path, X_OK) == 0)
		{
			cmd->access = 0;
			return (0);
		}
		else if (S_ISREG(st.st_mode) && access(path, F_OK) == 0)
		{
			cmd->access = 3;
			return (3);
		}
	}
	cmd->access = 1;
	return (1);
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

char	*is_path(char *prefix_cmd_name, char **tab_paths, t_cmd *cmd)
{
	int			i;
	char		*test_path;
	struct stat	st;

	i = 0;
	while (tab_paths && tab_paths[i])
	{
		test_path = ft_strjoin(tab_paths[i], prefix_cmd_name);
		if (!test_path)
			return (NULL);
		if (stat(test_path, &st) == 0)
		{
			if (S_ISREG(st.st_mode) && access(test_path, X_OK) == 0)
			{
				cmd->access = 0;
				return (test_path);
			}
		}
		free(test_path);
		i++;
	}
	return (NULL);
}

static char	**get_search_paths(t_env *env)
{
	char	*path;
	char	**paths;

	path = get_env_from_name("PATH", env);
	if (!path)
		path = get_env_from_name("PWD", env);
	paths = ft_split(path, ':');
	return (paths);
}

char	*cmd_path(t_env *env, char *cmd_name, t_cmd *cmd)
{
	char	**tab_paths;
	char	*prefix;
	char	*res_path;

	if (!cmd_name)
	{
		cmd->access = 1;
		return (NULL);
	}
	if (ft_strchr(cmd_name, '/'))
	{
		check_access(cmd_name, cmd);
		return (ft_strdup(cmd_name));
	}
	tab_paths = get_search_paths(env);
	prefix = ft_strjoin("/", cmd_name);
	res_path = is_path(prefix, tab_paths, cmd);
	free(prefix);
	free_tab(tab_paths);
	if (!res_path)
	{
		cmd->access = 1;
		return (ft_strdup(cmd_name));
	}
	return (res_path);
}
