/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:13:18 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/17 02:29:13 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal_status = 0;

int	event_hook(void)
{
	if (g_signal_status == SIGINT)
		rl_done = 1;
	return (0);
}

void	sig_handler(int signal)
{
	g_signal_status = signal;
	if (g_signal_status == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	signals(void)
{
	struct sigaction	act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = &sig_handler;
	sigemptyset(&act.sa_mask);
	if (isatty(STDIN_FILENO))
		rl_event_hook = event_hook;
	sigaction(SIGINT, &act, NULL);
	signal(SIGQUIT, SIG_IGN);
}
