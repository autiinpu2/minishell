/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:22:34 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/14 08:04:17 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	slen;
	char	*s2;

	slen = ft_strlen((char *)s);
	s2 = ft_calloc(slen + 1, sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
