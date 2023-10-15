/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:24:49 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 17:59:12 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	sig_her(int *p)
{
	int	fd;

	signal(SIGINT, inter_handler);
	if (!isatty(STDIN_FILENO))
	{
		fd = open(ttyname(STDERR_FILENO), O_RDONLY);
		close(p[0]);
		close(p[1]);
		return (true);
	}
	close(p[1]);
	return (false);
}

void	herdoc_sig(int i)
{
	(void)i;
	close(STDIN_FILENO);
}

void	inter_handler(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	rl_on_new_line();
	ft_putendl_fd("", 1);
	rl_redisplay();
	g_exit_status = 1;
}

void    sig_hand(int sig)
{
	if (sig == SIGINT)
		write(1, "", 1);
	if (sig == SIGQUIT)
		write(1, "Quit: 3", 7);
	exit(120 + sig);
}

void    sig_ch(pid_t pid)
{
	if (pid == 0)
	{
		signal(SIGINT, sig_hand);
		signal(SIGQUIT, sig_hand);
	}
	else
		signal(SIGINT, SIG_IGN);
}