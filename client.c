/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:17:51 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/15 16:30:37 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char *message)
{
	static int	bit = 0;
	int			i;

	i = 0;
	while (message[i] != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			if (message[i] & (1 << bit))// сравнивать побитово И 
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			pause();// засыпает до ожидания ответа    от сервера пока сервер не пришлет ответ ничего не будет делать//переводит процесс в непрерывный спя­ щий режим ядро не станет его «будить», пока он не получит сигнал. 
			usleep(700);//Функция usleep приостанавливает работу потока, в котором она была вызвана, на указанное в аргументе время в микросекундах или до поступления сигнала по которому вызывается функция обработки сигналов или программа завершает свою работу. 
		}
		i++;
	}
}

void	handler(int signum)//Он позволяет одной функции обрабатывать сразу много сигналов.
{
	(void)signum;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sigac;

	sigac.sa_handler = handler;//обрабатывет
	sigaction(SIGUSR1, &sigac, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid != 0)
			send_char(pid, argv[2]);
		else
			ft_putstr("Wrong PID");
	}
	else
		ft_putstr("Wrong input arguments");
	return (0);
}
