/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:35:09 by mcomin            #+#    #+#             */
/*   Updated: 2026/01/26 04:03:55 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"
#include "../includes/libft.h"

char	*find_cmd_path(t_env *env, char *cmd_name)
{
	char	*env_path;
	char	**tab_paths;
	char	*test_path;
	int		i;
	char	*prefix_cmd_name;

	if (access(cmd_name, X_OK) == 0)
		return(cmd_name);
	env_path = get_env_from_name("PATH", env);
	tab_paths = ft_split(env_path, ':');
	i = 0;
	prefix_cmd_name = ft_strjoin("/", cmd_name);
	while(tab_paths[i])
	{
		test_path = ft_strjoin(tab_paths[i], prefix_cmd_name);
		if (access(test_path, X_OK) == 0)
		{
			free(prefix_cmd_name);
			return(test_path);
		}
		else
			free(test_path);
		i++;
	}
	free(prefix_cmd_name);
	free(test_path);
	return (NULL);
}
