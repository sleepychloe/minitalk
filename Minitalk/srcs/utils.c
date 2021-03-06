/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:16 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/29 12:39:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	err_msg_pid(void)
{
	ft_printf("************************\n");
	ft_printf("****** PID ERROR *******\n");
	ft_printf("************************\n");
}

void	err_msg_arg(void)
{
	ft_printf("************************\n");
	ft_printf("*** INVALID ARGUMENT ***\n");
	ft_printf("************************\n");
	ft_printf("------------------------\n");
	ft_printf("--command---------------\n");
	ft_printf("--./client [PID] {MSG}--\n");
	ft_printf("------------------------\n");
}
