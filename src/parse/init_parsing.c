/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:35:09 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/04 01:58:43 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd		ft_init_cmd_is_pipe(t_data *data, int i)
{
	int		pipes[2];

	if (i == 0)
		data->cmds[i].infile = 0;
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
		data->cmds[i].outfile = 1;
	return (data->cmds[i]);
}

t_cmd		ft_init_cmd(char *token, t_env *env, t_data *data, int i)
{
	(void)env;
	data->cmds[i].args = ft_split(token, ' ');
	data->cmds[i].function_name = ft_strdup(data->cmds[i].args[0]);
	//data->cmds[i].is_build_in = is_built_in(data->cmds[i].function_name);
	//if (!data->cmds[i].is_build_in)
	//	data->cmds[i].path = ft_strdup(find_cmd_path(env, data->cmds[i].function_name));
	//else
	//	data->cmds[i].path = ft_strdup(data->cmds[i].function_name);
	//if (data->cmds[i].is_build_in == false && !tab->cmd[i].path)
	//	data->cmds[i].is_valid = false;
	if (!data->cmds[i].path)
		data->cmds[i].path = ft_strdup(data->cmds[i].function_name);
	ft_init_cmd_is_pipe(data, i);
	i++;
	return (data->cmds[i]);
}

t_data	*ft_init_data(char *input, t_env *env)
{
	char		**tab_split;
	t_data	*data;
	int			i;

	i = 0;
	tab_split = ft_split(input, '|');
	data = ft_calloc(1, sizeof(t_data));
	data->size = count_pipe(input) + 1;
	data->exit_code = EXIT_SUCCESS;
	data->cmds = ft_calloc(data->size + 2, sizeof(t_cmd));
	while ((size_t)i < data->size)
	{
		ft_init_cmd(tab_split[i], env, data, i);
		//if (data->cmds[i].is_valid == false)
		//{
		//	tab->is_valid = false;
		//	break ;
		//}
		i++;
	}
	free_tab(tab_split);
	return (data);
}
