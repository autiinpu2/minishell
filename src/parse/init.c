/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 05:22:34 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/12 06:50:52 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "exec.h"

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
		data->cmds[i].is_outfile_pipe = true;
		data->cmds[i + 1].is_infile_pipe = true;
	}
	else
		data->cmds[i].outfile = STDOUT_FILENO;
	return (data->cmds[i]);
}

t_cmd	new_cmd(char *token, t_data *data, int i)
{
	if (!token || !*token)
	{
		data->cmds[i].access = -1;
		return (data->cmds[i]);
	}
	data->cmds[i].args = ft_split_quotes(token, ' ');
	cmd_is_pipe(data, i);
	handle_redir(data);
	data->cmds[i].function_name = ft_strdup(data->cmds[i].args[0]);
	data->cmds[i].is_built_in = is_built_in(data->cmds[i].function_name);
	in_quotes(&data->cmds[i].function_name);
	if (!data->cmds[i].is_built_in)
		data->cmds[i].path = cmd_path(data->env,
				data->cmds[i].function_name, &data->cmds[i]);
	else
		data->cmds[i].path = ft_strdup(data->cmds[i].function_name);
	return (data->cmds[i]);
}

t_data	*		load_data(t_data *data, char *input)
{
	char		**tab_split;
	int			i;

	i = 0;
	tab_split = ft_split_quotes(input, '|');
	if (!tab_split)
		return (NULL);
	data->size = count_pipe(input) + 1;
	data->cmds = ft_calloc(data->size + 2, sizeof(t_cmd));
	if (!data->cmds)
		return (NULL);
	while ((size_t)i < data->size)
	{
		expand(&tab_split[i], data);
		tab_split[i] = wildcard(tab_split[i]);
		new_cmd(tab_split[i], data, i);
		i++;
	}
	free_tab(tab_split);
	return (data);
}

void	update_shlvl(t_data *data)
{
	int		value;
	char	*actual_value;
	char	*new_value;
	char	*endptr;

	actual_value = get_env_from_name("SHLVL", data->env);
	if (!actual_value)
	{
		new_value = ft_itoa(1);
		change_env_value(data, "SHLVL", new_value);
		free_single(new_value);
		return ;
	}
	value = ft_strtol(actual_value, &endptr);
	if (*endptr != '\0')
		value = 0;
	value += 1;
	new_value = ft_itoa(value);
	if (!new_value)
		return ;
	change_env_value(data, "SHLVL", new_value);
	free_single(new_value);
}

t_data	*init_data(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->cmds = NULL;
	data->size = 0;
	data->env = load_envp(envp);
	update_shlvl(data);
	data->exit_code = EXIT_SUCCESS;
	return (data);
}
