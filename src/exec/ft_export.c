/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:44:35 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/15 09:48:34 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "free.h"

void	create_new_var(char **args, t_data *data)
{
	t_env_node	*new_node;
	t_env_node	*curr;

	new_node = ft_calloc(1, sizeof(t_env_node));
	if (!new_node)
		return ;
	new_node->key = ft_strdup(args[0]);
	if (args[1])
		new_node->value = ft_strdup(args[1]);
	else
		new_node->value = ft_strdup("");
	new_node->text = ft_strjoin(new_node->key, "=");
	new_node->text = ft_strjoin_free(new_node->text, new_node->value);
	if (!data->env->top)
		data->env->top = new_node;
	else
	{
		curr = data->env->top;
		while (curr->next)
			curr = curr->next;
		curr->next = new_node;
	}
	data->env->size++;
}

void	add_new_env_node(t_data *data, char *arg)
{
	char		**args;

	args = export_split(arg, data);
	if (!args)
	{
		ft_dprintf(2, "export: `%s': not a valid identifier\n", arg);
		data->exit_code = 1;
		return ;
	}
	if (env_exist(args[0], data->env) && args[1])
		change_env_value(data, args[0], args[1]);
	else if (!args[1])
	{
		free_tab(args);
		return ;
	}
	else
		create_new_var(args, data);
	free_tab(args);
}

int	ft_export(t_data *data, t_cmd cmd)
{
	size_t	len_args;
	size_t	i;
	int		stdout;

	len_args = get_args_number(cmd.args);
	duplicate_outfile(cmd.infile, cmd.outfile, &stdout);
	if (len_args == 1)
	{
		print_export(data->env);
		restore_fd(stdout, STDOUT_FILENO);
		return (0);
	}
	i = 0;
	while (i < len_args - 1)
	{
		if (data->size == 1)
			add_new_env_node(data, cmd.args[i + 1]);
		i++;
	}
	restore_fd(stdout, STDOUT_FILENO);
	return (data->exit_code);
}
