/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 04:14:43 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/24 04:14:43 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*st;
	int		size;
	char	*res;

	st = (char *)s;
	i = 0;
	res = NULL;
	size = ft_strlen(st);
	while (size > i)
	{
		if (st[i] == (unsigned char)c)
			res = st + i;
		i++;
	}
	if (st[i] == (unsigned char)c)
		return (st + i);
	return (res);
}
