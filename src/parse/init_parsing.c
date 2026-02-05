/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <marvin@d42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 05:22:34 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/05 05:22:34 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"

t_cmd		cmd_is_pipe(t_data *data, int i)
{
	int		pipes[2];

	if (i == 0)
		data->cmds[i].infile = STDIN_FILENO;
	if (i + 1 < (int)data->size)
	{
		if (pipe(pipes) == -1)
		{
			perror("pipe");
			return (data->cmds[i]);
		}
		data->cmds[i].outfile = pipes[1];
		data->cmds[i + 1].infile = pipes[0];	
	}
	else
		data->cmds[i].outfile = STDOUT_FILENO;
	return (data->cmds[i]);
}

t_cmd	new_cmd(char *token, t_data *data, int i)
{
	data->cmds[i].args = ft_split(token, ' ');
	data->cmds[i].function_name = ft_strdup(data->cmds[i].args[0]);
	data->cmds[i].is_built_in = is_built_in(data->cmds[i].function_name);
	if (!data->cmds[i].is_built_in)
		data->cmds[i].path = ft_strdup(cmd_path(data->env, data->cmds[i].function_name));
	else
		data->cmds[i].path = ft_strdup(data->cmds[i].function_name);
	if (!data->cmds[i].path)
		data->cmds[i].path = ft_strdup(data->cmds[i].function_name);
	cmd_is_pipe(data, i);
	i++;
	return (data->cmds[i]);
}

t_data	*load_data(t_data *data, char *input)
{
	char		**tab_split;
	int			i;

	i = 0;
	tab_split = ft_split(input, '|');
	data->size = count_pipe(input) + 1;
	data->cmds = ft_calloc(data->size + 2, sizeof(t_cmd));
	while ((size_t)i < data->size)
	{
		new_cmd(tab_split[i], data, i);
		i++;
	}
	free_tab(tab_split);
	return (data);
}
t_data	*new_data(char **envp)
{
	t_data	*data;
	
	data = ft_calloc(1, sizeof(t_data));
	data->cmds = NULL;
	data->size = 0;
	data->env = load_envp(envp);
	data->exit_code = EXIT_SUCCESS;
	return (data);	
}
