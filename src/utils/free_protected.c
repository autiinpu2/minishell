/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_protected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:02:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/13 04:48:02 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_single(void *s)
{
	if (s)
		free(s);
}

void	free_double(void *s1, void *s2)
{
	free_single(s1);
	free_single(s2);
}
