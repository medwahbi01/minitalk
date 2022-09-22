/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwahbi <mwahbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:25:52 by mwahbi            #+#    #+#             */
/*   Updated: 2022/09/21 20:06:13 by mwahbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk_bonus.h"

void	sendb(int id, char bit)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((bit >> i) & 1)
			kill(id, SIGUSR1);
		else
			kill(id, SIGUSR2);
		i--;
		usleep(500);
	}
}

void	sendmsg(char *string, int pid)
{
	int	i;

	i = -1;
	while (string[++i])
		sendb(pid, string[i]);
	sendb(pid, '\0');
}

void	handler(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr("signal sent successufuly :) \n");
}

int	main(int ac, char **av)
{
	int		id;
	char	*string;

	signal(SIGUSR2, &handler);
	if (ac != 3)
	{
		ft_putstr("Usage: ./client [PID] [string]\n");
		exit(1);
	}
	id = ft_atoi(av[1]);
	string = av[2];
	sendmsg(string, id);
	return (0);
}
