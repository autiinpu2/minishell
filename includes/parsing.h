/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:27:45 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/11 09:07:18 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <sys/stat.h>
# include "minishell.h"
# include "env.h"
# include "libft.h"
# include "free.h"

char	*supp_quotes(char *str);
int		count_quotes_closed(char *str);
int		is_in_quotes(char const *s, size_t pos);
char	**ft_split_quotes(char const *s, char c);
t_data	*load_data(t_data *data, char *input);
int		count_pipe(char *input);
char	*is_path(char *prefix_cmd_name, char **tab_paths);
char	*cmd_path(t_env *env, char *cmd_name);
int		is_empty_or_spaces(char *input);

void	expand(char **tab_split, t_data *data);

#endif
