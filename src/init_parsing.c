/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:35:09 by mcomin            #+#    #+#             */
/*   Updated: 2026/01/27 05:19:46 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"

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
		else
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
	free(prefix_cmd_name);
	return (test_path);
}

t_cmd	*parsing(t_env *env, char *line)
{
	t_cmd	*cmd;
	char	**line_elements;

	cmd = ft_calloc(1, sizeof(t_cmd));
	line_elements = ft_split(line, ' ');
	cmd->path = find_cmd_path(env, line_elements[0]);
	if (cmd->path || cmd->is_build_in)
		cmd->function_name = line_elements[0];
	return (cmd);
}
