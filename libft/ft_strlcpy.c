/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 04:12:38 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/24 04:12:39 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > i && (size_t)ft_strlen((char *)src) >= i)
	{
		dst[i] = src[i];
		i++;
	}
	if (i > 0)
		dst[--i] = '\0';
	return (ft_strlen((char *)src));
}
