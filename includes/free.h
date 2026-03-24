/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:59:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/24 06:48:43 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "minishell.h"
# include "env.h"
# include <stdarg.h>

void	free_data(t_data *data);
void	free_env(t_env *env);
void	free_tab(char **tab);
void	free_single(void *s);
void	free_var(int n, ...);
void	free_cmds(t_data *data);

#endif