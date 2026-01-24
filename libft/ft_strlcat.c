/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 04:11:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/24 04:27:06 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	i;

	if (dst)
		dest_size = ft_strlen(dst);
	i = 0;
	if (size == 0 || ((size_t)ft_strlen(dst)) >= size)
		return (size + ft_strlen((char *)src));
	while (src[i] && dest_size + 1 < size)
	{
		dst[dest_size++] = src[i++];
	}
	dst[dest_size] = '\0';
	return (dest_size + ft_strlen((char *)src) - i);
}
