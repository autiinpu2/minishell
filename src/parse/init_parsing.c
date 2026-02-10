/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 05:22:34 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/10 01:24:34 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd	cmd_is_pipe(t_data *data, int i)
{
	int	pipes[2];

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
	data->cmds[i].args = ft_split_quotes(token, ' ');
	data->cmds[i].function_name = ft_strdup(data->cmds[i].args[0]);
	data->cmds[i].is_built_in = is_built_in(data->cmds[i].function_name);
	if (!data->cmds[i].is_built_in)
		data->cmds[i].path = cmd_path(data->env, data->cmds[i].function_name);
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
	expand(tab_split, data);
	while ((size_t)i < data->size)
	{
		new_cmd(tab_split[i], data, i);
		i++;
	}
	free_tab(tab_split);
	return (data);
}

void	update_shlvl(t_env *env)
{
	int		value;
	char	*actual_value;
	char	*new_value;

	actual_value = get_env_from_name("SHLVL", env);
	value = ft_strtol(actual_value, NULL);
	value += 1;
	new_value = ft_itoa(value);
	change_env_value(env, "SHLVL", new_value);
	free(new_value);
}

t_data	*new_data(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->cmds = NULL;
	data->size = 0;
	data->env = load_envp(envp);
	update_shlvl(data->env);
	data->exit_code = EXIT_SUCCESS;
	return (data);
}
