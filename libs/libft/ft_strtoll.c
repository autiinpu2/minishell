/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:11:23 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/05 07:59:16 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static void	skip_beginning(const char *nptr, int *i, int *sign)
{
	while (nptr[*i] && ft_is_space(nptr[*i]))
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

long long	ft_strtoll(const char *nptr, char **endptr)
{
	long long	n;
	int			sign;
	int			i;
	int			digits;

	n = 0;
	sign = 1;
	i = 0;
	digits = 0;
	skip_beginning(nptr, &i, &sign);
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (sign == 1 && n > (LLONG_MAX - (nptr[i] - '0')) / 10)
			return (LLONG_MAX);
		else if (sign == -1 && (-n) < (LLONG_MIN + (nptr[i] - '0')) / 10)
			return (LLONG_MIN);
		n = n * 10 + nptr[i] - '0';
		i++;
		digits++;
	}
	if (digits == 0)
		i = 0;
	if (endptr)
		*endptr = (char *)(nptr + i);
	return (n * sign);
}
