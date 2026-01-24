/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:03:22 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/19 23:06:44 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	s = malloc(s1_length + s2_length + 1);
	if (!s)
		return (NULL);
	while (i < s1_length)
	{
		s[i] = s1[i];
		i++;
	}
	while (j < s2_length)
		s[i++] = s2[j++];
	s[s1_length + s2_length] = '\0';
	return (s);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	s = malloc(s1_length + s2_length + 1);
	if (!s)
		return (NULL);
	while (i < s1_length)
	{
		s[i] = s1[i];
		i++;
	}
	while (j < s2_length)
		s[i++] = s2[j++];
	s[s1_length + s2_length] = '\0';
	free(s1);
	return (s);
}
