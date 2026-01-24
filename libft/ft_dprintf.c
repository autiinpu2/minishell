/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:59:49 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/24 04:19:24 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_elems(t_dprintf struc, va_list args, int fd)
{
	if (struc.format[struc.i] == '%')
		struc.printed_char += ft_putchar_fd('%', fd);
	else if (struc.format[struc.i] == 'c')
		struc.printed_char += ft_putchar_fd(va_arg(args, int), fd);
	else if (struc.format[struc.i] == 's')
		struc.printed_char += ft_putstr_fd(va_arg(args, char *), fd);
	else if (struc.format[struc.i] == 'd'
		|| struc.format[struc.i] == 'i')
		struc.printed_char += ft_putnbr_fd(va_arg(args, int), fd);
	else
	{
		struc.printed_char += ft_putchar_fd('%', fd);
		struc.printed_char += ft_putchar_fd(struc.format[struc.i], fd);
	}
	return (struc.printed_char);
}

static t_dprintf	get_struct(int i, int printed_char, const char *format)
{
	t_dprintf	structure;

	structure.format = format;
	structure.i = i;
	structure.printed_char = printed_char;
	return (structure);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int			i;
	int			printed_char;
	t_dprintf	dprintf_struct;
	va_list		args;

	if (!format)
		return (-1);
	i = 0;
	va_start(args, format);
	printed_char = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			dprintf_struct = get_struct(i, printed_char, format);
			printed_char = print_elems(dprintf_struct, args, fd);
			i++;
		}
		else
			printed_char += ft_putchar_fd(format[i++], fd);
	}
	va_end(args);
	return (printed_char);
}
