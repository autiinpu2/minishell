/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 03:33:49 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/19 03:40:00 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (s >= d)
		d = ft_memcpy(d, s, n);
	else
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (d);
}
