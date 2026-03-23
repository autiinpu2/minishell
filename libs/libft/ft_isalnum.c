/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:27:21 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/21 22:51:49 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

bool	ft_isalnum_string(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isalnum(s[i]))
			return (false);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}
