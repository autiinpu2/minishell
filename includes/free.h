/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:59:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/04 00:39:45 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "minishell.h"
# include "env.h"

void	free_data(t_data *data);
void	free_env(t_env *env);
void	free_tab(char **tab);
void	free_single(void *s);
void	free_double(void *s1, void *s2);

#endif