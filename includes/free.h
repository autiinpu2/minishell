/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:59:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/03 03:17:31 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "minishell.h"
# include "env.h"

void		free_tab_cmd(t_tab_cmd *cmd);
void		free_env(t_env *env);
void		free_tab(char **tab);
void		free_single(void *s);
void		free_double(void *s1, void *s2);

#endif