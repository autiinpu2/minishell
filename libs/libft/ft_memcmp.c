/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:08:03 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/18 21:08:41 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1b;
	const unsigned char	*s2b;

	s1b = (const unsigned char *)s1;
	s2b = (const unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (s1b[i] == s2b[i] && n > (i + 1))
		i++;
	return (s1b[i] - s2b[i]);
}
