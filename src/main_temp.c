/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:17:27 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/26 04:46:16 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"

int main(int ac, char **av, char **envp)
{
	char	*prefix;
	char	*line;
	t_env	*env;
	int		exit_code;
	
	(void)ac;
	(void)av;
	env = load_envp(envp);
	exit_code = EXIT_SUCCESS;
	while (true)
	{
		prefix = ft_strdup(get_env_from_name("PWD", env));
		prefix = ft_strjoin_free(prefix, ">");
		line = readline(prefix);
		printf("\n%s\n", find_cmd_path(env, line));
		free(line);
		free(prefix);
	}
	if (line)
		free(line);
	free(prefix);
	free(env);
	return(exit_code);
}
