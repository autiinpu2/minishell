/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:27:45 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/17 00:28:53 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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
char	*is_path(char *prefix_cmd_name, char **tab_paths, t_cmd *cmd);
char	*cmd_path(t_env *env, char *cmd_name, t_cmd *cmd);
int		is_empty_or_spaces(char *input);

void	expand(char **tab_split, t_data *data);
char	*get_expanded_string(char *string, int begin, int end, t_data *data);
char	*get_expanded_home(char *string, int begin, int end, t_data *data);
char	*ft_exit_code(t_data *data, char *str_begin);
char	*remove_char_i(char *str, int index);
int		get_quote_state(char *string, size_t pos);

#endif
