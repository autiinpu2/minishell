/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 05:40:43 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/19 08:51:06 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	in_quotes(char **str)
{
	char	*tmp;

	if (count_quotes_closed(*str))
	{
		tmp = supp_quotes(*str);
		free_single(*str);
		*str = ft_strdup(tmp);
		free_single(tmp);
	}
}

bool	is_only_quotes(char *arg)
{
	return (!ft_strcmp(arg, "\"\"") || !ft_strcmp(arg, "\'\'"));
}
