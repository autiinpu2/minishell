/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:00:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/27 09:01:03 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

static int	frees(char **str, int j)
{
	if (!str[j])
	{
		while (j--)
			free(str[j]);
		free(str);
		return (0);
	}
	return (1);
}

static char	**do_malloc(char const *s, char c, int n)
{
	char	**str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	str = ft_calloc(n + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (j < n)
	{
		len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		str[j] = ft_calloc(len + 1, sizeof(char));
		if (!frees(str, j++))
			return (NULL);
	}
	return (str);
}

static char	**fill_str(char const *s, char c, int n, char **str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < n && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		k = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				str[j][k++] = s[i++];
			j++;
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**str;

	if (!s)
		return (NULL);
	n = get_len(s, c);
	str = do_malloc(s, c, n);
	if (!str)
		return (NULL);
	str = fill_str(s, c, n, str);
	return (str);
}
