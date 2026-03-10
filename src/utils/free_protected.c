/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_protected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:02:40 by apuyane           #+#    #+#             */
/*   Updated: 2026/03/10 01:52:20 by mcomin           ###   ########.fr       */
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
