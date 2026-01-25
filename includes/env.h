/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 03:34:34 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/25 06:10:33 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include <stdlib.h>

typedef struct s_env_node
{
	char			*key;
	char			*value;
	struct s_env_node	*next;
}					t_env_node;

typedef struct s_env
{
	int				size;
	struct s_env_node	*top;
}				t_env;

void	print_env(t_env *env);
t_env	*load_envp(char **envp);

#endif
