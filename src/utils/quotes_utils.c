/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 05:40:43 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/21 04:25:34 by apuyane          ###   ########.fr       */
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
	int	ret;

	ret = (!ft_strcmp(arg, "\"\"")) || (!ft_strcmp(arg, "\'\'"));
	return (ret);
}
