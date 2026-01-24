/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:02:21 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/19 23:19:37 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	if (!n)
		return (NULL);
	while (n < (size_t)i)
	{
		if (s2[i] == c)
			return (s2 + i);
		i++;
	}
	if ((size_t)i == n)
		return (NULL);
	if (c == '\0')
		return (s2 + i);
	return (NULL);
}
