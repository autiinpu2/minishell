/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:27:45 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/05 05:01:18 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "env.h"
# include "libft.h"
# include "free.h"

t_data	*load_data(t_data *data, char *input);
int	    count_pipe(char *input);
char	*is_path(char *prefix_cmd_name, char **tab_paths);
char	*cmd_path(t_env *env, char *cmd_name);
int     is_empty_or_spaces(char *input);

#endif
