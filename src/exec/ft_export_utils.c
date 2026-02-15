/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:13:37 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/15 09:39:29 by apuyane          ###   ########.fr       */
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

void	print_export(t_env *env)
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
		if (get_env_from_name(text[0], env))
			ft_dprintf(1, "\"%s\"\n", get_env_from_name(text[0], env));
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
		tab[1] = ft_strjoin(get_env_from_name(tab[0], data->env), arg + i + 2);
	else if (arg[i] == '=')
		tab[1] = ft_strdup(arg + i + 1);
	else
		tab[1] = NULL;
	return (tab);
}
