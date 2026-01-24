/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 01:01:21 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/24 04:03:09 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*st;

	st = (char *)s;
	i = 0;
	while (st[i])
	{
		if (st[i] == (unsigned char)c)
			return (st + i);
		i++;
	}
	if (st[i] == (unsigned char)c)
		return (st + i);
	return (NULL);
}
