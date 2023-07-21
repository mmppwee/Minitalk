# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 21:38:32 by pwareepo          #+#    #+#              #
#    Updated: 2023/07/21 19:16:42 by pwareepo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_SRCS =	ft_printf/ft_printf.c\
					ft_printf/ft_cspdi.c\
					ft_printf/ft_uxX.c
HEADER =	ft_printf/ft_printf.h

all: $(NAME)

$(NAME): server client

server:
	gcc $(CFLAGS) $(FT_PRINTF_SRCS) server.c -I $(HEADER) -o server

client:
	gcc $(CFLAGS) $(FT_PRINTF_SRCS) client.c -I $(HEADER) -o client

clean:
	rm -f server
	rm -f client

fclean: clean

re: fclean all

.PHONY: all clean fclean re
