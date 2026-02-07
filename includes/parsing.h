/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:27:45 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/06 23:10:24 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <sys/stat.h>

# include "minishell.h"
# include "env.h"
# include "libft.h"
# include "free.h"

char	**ft_split_quotes(char const *s, char c);
t_data	*load_data(t_data *data, char *input);
int		count_pipe(char *input);
char	*is_path(char *prefix_cmd_name, char **tab_paths);
char	*cmd_path(t_env *env, char *cmd_name);
int		is_empty_or_spaces(char *input);

#endif
