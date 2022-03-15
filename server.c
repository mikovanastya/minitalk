/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:54:11 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/15 16:32:19 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int		bit = 0;
	static char		message = 0;
	static pid_t	pid;

	(void)context;
	if (pid != siginfo->si_pid)
	{
		bit = 0;
		message = 0;
		pid = siginfo->si_pid;
	}
	if (signum == SIGUSR1)
		message |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &message, 1);
		bit = 0;
		message = 0;
	}
	usleep(700);
	kill(siginfo->si_pid, SIGUSR1);// сервер отправляет обратно сигнал, который получил
}

int	main(void)
{
	struct sigaction	sigac;

	ft_putstr("server pid: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sigac.sa_sigaction = signal_handler;// принимает и отрабатывает, направляет сигнал на функцию sigaction
	sigac.sa_flags = SA_SIGINFO;//задаем функцию с 3 параметрами
	sigaction(SIGUSR1, &sigac, NULL);//принимает сигналы
	sigaction(SIGUSR2, &sigac, NULL);
	while (1)
		pause();// бессконечный цикл, который ожидает сигнал
	return (0);
}
