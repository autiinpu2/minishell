/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:44:35 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/14 10:41:37 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "free.h"

void	sort_envp(char **envp, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (i + 1 < len)
	{
		if (ft_strcmp(envp[i], envp[i + 1]) > 0)
		{
			tmp = envp[i];
			envp[i] = envp[i + 1];
			envp[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void	print_export(t_env *env)
{
	char	**envp;
	size_t	len;
	char	**text;
	size_t	i;

	i = 0;
	envp = env_to_envp(env);
	len = get_args_number(envp);
	sort_envp(envp, len);
	while (i < len)
	{
		text = ft_split(envp[i], '=');
		ft_dprintf(1, "declare -x %s=", text[0]);
		if (text[1])
			ft_dprintf(1, "\"%s\"\n", text[1]);
		else
			ft_dprintf(1, "\n");
		free_tab(text);
		i++;
	}
	free_tab(envp);
}

char	**export_split(char *arg, t_data *data)
{
	int		i;
	char	**tab;
	char	*old_val;

	i = 0;
	if (!arg || !ft_isalpha(arg[i]))
		return (NULL);
	while (arg[i] && (ft_isalnum(arg[i]) || arg[i] == '_'))
		i++;
	if (arg[i] != '\0' && arg[i] != '='
		&& !(arg[i] == '+' && arg[i + 1] == '='))
		return (NULL);
	tab = ft_calloc(3, sizeof(char *));
	if (!tab)
		return (NULL);
	tab[0] = ft_substr(arg, 0, i);
	if (arg[i] == '+')
	{
		old_val = get_env_from_name(tab[0], data->env);
		tab[1] = ft_strjoin(old_val, arg + i + 2);
	}
	else if (arg[i] == '=')
		tab[1] = ft_strdup(arg + i + 1);
	return (tab);
}

void	add_new_env_node(t_data *data, char *arg)
{
	char		**args;
	t_env_node	*new_node;
	t_env_node	*curr;

	args = export_split(arg, data);
	if (!args)
	{
		ft_dprintf(2, "export: `%s': not a valid identifier\n", arg);
		data->exit_code = 1;
		return ;
	}
	if (env_exist(args[0], data->env))
		change_env_value(data, args[0], args[1]);
	else
	{
		new_node = ft_calloc(1, sizeof(t_env_node));
		if (!new_node)
			return ;
		new_node->key = ft_strdup(args[0]);
		if (args[1])
			new_node->value = ft_strdup(args[1]);
		else
			new_node->value = ft_strdup("");
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
