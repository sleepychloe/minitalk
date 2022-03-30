/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:22:30 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/29 13:03:15 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	ft_make_sig(int pid_server, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit & 1) == 0)
			kill(pid_server, SIGUSR1);
		else if ((c >> bit & 1) == 1)
			kill(pid_server, SIGUSR2);
		usleep(200);
	}
}

void	ft_transmit(int pid_server, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_make_sig(pid_server, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		if (pid_server <= 0)
			err_msg_pid();
		ft_transmit(pid_server, argv[2]);
	}
	else
		err_msg_arg();
	return (0);
}
