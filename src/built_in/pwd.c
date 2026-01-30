/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:14:33 by apuyane           #+#    #+#             */
/*   Updated: 2026/01/30 11:03:57 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_pwd(t_env *env, t_built_in *built, int i)
{
	int         stdout_backup;

	stdout_backup = dup(STDOUT_FILENO);
	dup2(built->tab->cmd[i].outfile, STDOUT_FILENO);
	printf("%s\n", get_env_from_name("PWD", env));
	dup2(stdout_backup, STDOUT_FILENO);
	close(stdout_backup);
}
