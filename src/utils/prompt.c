/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:28:36 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/15 13:38:36 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "exec.h"
#include "free.h"

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BROWN "\033[;33m"

char	*color(char *s, char *color)
{
	char	*s2;

	s2 = ft_strjoin(color, s);
	s2 = ft_strjoin_free(s2, RESET);
	return (s2);
}

char	*get_branch_name(t_data *data)
{
	int		fd;
	char	*path;
	char	buff[100];
	char	*name;
	int		bytes;

	path = get_env_from_name("PWD", data->env);
	if (!path)
		return (NULL);
	path = ft_strjoin(path, "/.git/HEAD");
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
		return (NULL);
	bytes = read(fd, buff, 99);
	close(fd);
	if (bytes <= 0)
		return (NULL);
	buff[bytes] = '\0';
	name = ft_strrchr(buff, '/');
	if (!name)
		return (NULL);
	name = ft_substr(name + 1, 0, ft_strlen(name + 1) - 1);
	return (name);
}

char	*get_git(t_data *data)
{
	char	*display;
	char	*branch_name;
	char	*git;

	display = get_env_from_name("GIT_DISPLAY", data->env);
	if (!display || ft_strcmp(display, "yes"))
		return (NULL);
	branch_name = get_branch_name(data);
	if (!branch_name)
		return (ft_strdup(""));
	git = ft_strjoin(BROWN, "git:(");
	git = ft_strjoin_free(git, RED);
	git = ft_strjoin_free(git, branch_name);
	git = ft_strjoin_free(git, BROWN);
	git = ft_strjoin_free(git, ") ");
	git = ft_strjoin_free(git, RESET);
	free(branch_name);
	return (git);
}

static char	*get_exit_code(t_data *data)
{
	char	*exit_code;
	char	*prompt;

	exit_code = ft_itoa(data->exit_code);
	exit_code = ft_strjoin_free(exit_code, " ➜ ");
	if (data->exit_code == 0)
		prompt = ft_strjoin(GREEN, exit_code);
	else
		prompt = ft_strjoin(RED, exit_code);
	prompt = ft_strjoin_free(prompt, RESET);
	free_single(exit_code);
	return (prompt);
}

char	*get_prefix(t_data *data)
{
	char	*pwd;
	char	*prompt;
	char	*git;

	prompt = get_exit_code(data);
	pwd = get_env_from_name("PWD", data->env);
	if (!pwd)
		pwd = getcwd(NULL, 0);
	else
		pwd = ft_strdup(pwd);
	prompt = ft_strjoin_free(prompt, pwd);
	free(pwd);
	git = get_git(data);
	prompt = ft_strjoin_free(prompt, "> ");
	prompt = ft_strjoin_free(prompt, git);
	free(git);
	return (prompt);
}
