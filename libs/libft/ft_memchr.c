/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:02:21 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/06 17:01:00 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;

	s2 = (char *)s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n > i)
	{
		if (s2[i] == (char)c)
			return (s2 + i);
		i++;
	}
	if (i == n)
		return (NULL);
	if ((char)c == '\0')
		return (s2 + i);
	return (NULL);
}
