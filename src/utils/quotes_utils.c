/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 05:40:43 by mcomin            #+#    #+#             */
/*   Updated: 2026/03/19 06:09:16 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	in_quotes(char *str)
{
	char	*tmp;

	if (count_quotes_closed(str))
	{
		tmp = supp_quotes(str);
		free_single(str);
		str = ft_strdup(tmp);
		free_single(tmp);
	}
}
