/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:06:24 by pwareepo          #+#    #+#             */
/*   Updated: 2023/07/21 19:51:36 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <sys/types.h>

void	signal_handler(int signum, siginfo_t *info, void *ucontext);

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	server_pid = getpid();
	ft_printf("%d\n", server_pid);
	sa.sa_sigaction = signal_handler;
	sigemptyset (&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	current_char;
	static int				bit_index;

	(void)info;
	(void)ucontext;
	current_char |= (signum == SIGUSR2);
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", current_char);
		current_char = 0;
		bit_index = 0;
	}
	else
		current_char <<= 1;
}
