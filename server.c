/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:06:24 by pwareepo          #+#    #+#             */
/*   Updated: 2023/07/11 22:12:28 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>

void	signal_handler(int sig)
{
	static unsigned char current_char;
	static int bit_index;

	current_char |= (sig == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		
	}
}