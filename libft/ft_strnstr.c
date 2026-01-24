/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 04:14:21 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/24 04:27:50 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len < 0)
		len = (size_t)ft_strlen((char *)big);
	while (big[j] && j < len)
	{
		if (big[j] == little[i] && i < len)
		{
			j++;
			i++;
		}
		else if (!(little[i]) || i >= len)
			return ((char *)big + j - i);
		else
		{
			j = j - i + 1;
			i = 0;
		}
	}
	if (!(little[i]))
		return ((char *)big + j - i);
	return (NULL);
}
