/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwahbi <mwahbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:43:50 by mwahbi            #+#    #+#             */
/*   Updated: 2022/09/18 17:40:40 by mwahbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

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
}

int	main(int ac, char **av)
{
	int		id;
	char	*string;

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
