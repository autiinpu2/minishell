/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 04:09:41 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/19 23:48:56 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	int	return_value;

	return_value = 0;
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		return_value++;
	}
	if (nb > 9)
	{
		return_value += ft_putnbr(nb / 10);
		return_value += ft_putnbr(nb % 10);
	}
	else
		return_value += ft_putchar_fd(nb + '0', 1);
	return (return_value);
}
