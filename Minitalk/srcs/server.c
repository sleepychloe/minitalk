/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:22:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/29 13:59:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	ft_signal(int sig)
{
	static int	cnt;
	static int	c;

	cnt++;
	c = c << 1;
	if (sig == SIGUSR2)
		c++;
	if (cnt == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0x0;
		cnt = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (100 < pid && pid <= 32768)
	{
		ft_printf("%d\n", pid);
		while (1)
		{
			signal(SIGUSR1, ft_signal);
			signal(SIGUSR2, ft_signal);
			pause();
		}
	}
	else
		err_msg_pid();
	return (0);
}
