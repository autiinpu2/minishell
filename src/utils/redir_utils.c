/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:47:14 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/18 00:22:53 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_redir(char *arg)
{
	if (!arg || !*arg)
		return (false);
	if ((arg[0] == '>' && arg[1] == '>') || (arg[0] == '<' && arg[1] == '<'))
	{
		if (arg[2] == '>' || arg[2] == '<')
			return (false);	
		return (true);
	}
	if (arg[0] == '>' || arg[0] == '<')
	{
		if (arg[1] == '>' || arg[1] == '<')
			return (false);	
		return (true);
	}
	return (false);
}
