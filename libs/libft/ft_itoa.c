/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:00:29 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/06 17:00:36 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_number(long n)
{
	int	d;

	d = 0;
	if (n <= 0)
		d = 1;
	while (n)
	{
		d++;
		n /= 10;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	char	*number;
	long	num;
	int		digits;

	num = n;
	digits = get_digit_number(num);
	number = ft_calloc(digits + 1, sizeof(char));
	if (!number)
		return (NULL);
	if (num < 0)
	{
		number[0] = '-';
		num = -num;
	}
	else if (!num)
		number[0] = '0';
	while (num)
	{
		number[--digits] = num % 10 + '0';
		num /= 10;
	}
	return (number);
}
