/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:03:57 by rtwitch           #+#    #+#             */
/*   Updated: 2022/01/27 15:46:14 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	send_char(pid_t pid, char *message);
void	handler(int signum);
void	signal_handler(int signum, siginfo_t *siginfo, void *context);

int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *str);

#endif