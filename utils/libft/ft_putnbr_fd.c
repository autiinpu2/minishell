/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 04:14:49 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/19 23:49:06 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int nb, int fd)
{
	int		return_value;
	char	*value;

	return_value = 0;
	value = ft_itoa(nb);
	return_value = write(fd, value, ft_strlen(value));
	free(value);
	return (return_value);
}
