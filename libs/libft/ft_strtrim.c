/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 04:18:20 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/24 04:18:20 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_last_non_set(char const *s1, char const *set)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s1[i])
	{
		if (is_in_set(s1[i], set) == 0)
		{
			i++;
			c = i;
		}
		else
			i++;
	}
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		n;
	int		j;

	i = 0;
	n = 0;
	if (!set || !s1)
		return (NULL);
	j = get_last_non_set(s1, set);
	while (s1[i] && set && is_in_set(s1[i], set))
		i++;
	if (j < i)
		j = i;
	s2 = malloc(j - i + 1);
	if (!s2)
		return (NULL);
	while (j > i)
	{
		s2[n] = s1[i];
		n++;
		i++;
	}
	s2[n] = '\0';
	return (s2);
}
