/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 04:13:09 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/24 04:13:09 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1b[i] && s2b[i] && s1b[i] == s2b[i] && n > i + 1)
	{
		i++;
	}
	return (s1b[i] - s2b[i]);
}
