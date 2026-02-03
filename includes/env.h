/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 03:34:34 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 03:14:27 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env_node
{
	char				*key;
	char				*value;
	char				*text;
	struct s_env_node	*next;
}					t_env_node;

typedef struct s_env
{
	int			size;
	t_env_node	*top;
}				t_env;

t_env	*load_envp(char **envp);
char	*get_env_from_name(char *name, t_env *env);
t_env	*change_env_value(t_env *env, char *key, char *new_value);

#endif
