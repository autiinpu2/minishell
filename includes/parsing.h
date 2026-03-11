/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:27:45 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/11 03:45:45 by mcomin           ###   ########.fr       */
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

void	expand(char **line, t_data *data);
char	*get_expanded_string(char *string, int begin, int end, t_data *data);
char	*get_expanded_home(char *string, int begin, int end, t_data *data);
char	*ft_exit_code(t_data *data, char *str_begin);
char	*remove_char_i(char *str, int index);
int		get_quote_state(char *string, size_t pos);
bool	is_redir(char *arg);
int		handle_redir(t_data *data);
int		redir_1(t_data *data, int i, int cmd_idx);
int		redir_2(t_data *data, int i, int cmd_idx);
int		redir_3(t_data *data, int i, int cmd_idx);
int		redir_4(t_data *data, int i, int cmd_idx);
int		is_in_tab(char **tab, char *str);
int		tab_size(char **tab);
int		redir_count(char **args);
char	*reload_input_redir(char *input, int redir);
int		count_redir_input(char *input);
void	init_initial_input(t_data *data,char *line);

#endif