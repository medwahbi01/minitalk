/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwahbi <mwahbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:30:15 by mwahbi            #+#    #+#             */
/*   Updated: 2022/09/18 17:39:42 by mwahbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;
	static int	s_pid;

	(void) ucontext;
	if (s_pid && s_pid != info->si_pid)
	{
		c = 0;
		i = 0;
	}
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	if (++i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	s_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	ac;

	ft_putstr("our pid is :     ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	ac.sa_sigaction = &handler;
	ac.sa_flags = SA_SIGINFO;
	sigemptyset(&ac.sa_mask);
	sigaction(SIGUSR1, &ac, NULL);
	sigaction(SIGUSR2, &ac, NULL);
	while (2000)
		pause();
}
