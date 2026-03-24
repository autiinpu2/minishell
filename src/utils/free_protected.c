/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_protected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:02:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/24 06:52:38 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_single(void *s)
{
	if (s)
		free(s);
	s = NULL;
}

void	free_var(int n, ...)
{
	int		i;
	va_list	args;
	void	*ptr;

	i = 0;
	va_start(args, n);
	while (i < n)
	{
		ptr = va_arg(args, void *);
		if (ptr)
			free_single(ptr);
		i++;
	}
	va_end(args);
}
