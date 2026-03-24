/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 01:01:21 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/24 07:45:42 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*st;

	st = (char *)s;
	i = 0;
	if (!st)
		return (NULL);
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
