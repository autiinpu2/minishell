/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:02:12 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/19 02:46:03 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*s;

	if (!size)
	{
		s = malloc(0);
		return (s);
	}
	total_size = nmemb * size;
	if (total_size / size != nmemb)
		return (NULL);
	s = malloc(total_size);
	if (!s)
		return (NULL);
	ft_bzero(s, total_size);
	return (s);
}
