/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:16:51 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/26 04:11:52 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_cmd
{
	int		infile;
	char	*path;
	char	**args;
	int		outfile;
	int		is_build_in;
	char	*function_name;
	t_cmd	*next;
}			t_cmd;

#endif
