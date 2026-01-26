/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 03:34:34 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/26 05:03:39 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
}					t_env_node;

typedef struct s_env
{
	int			size;
	t_env_node	*top;
}				t_env;

t_env	*load_envp(char **envp);
void	print_env(t_env *env);
char	*get_env_from_name(char *name, t_env *env);

#endif
