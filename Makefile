# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 16:17:25 by rtwitch           #+#    #+#              #
#    Updated: 2022/01/24 20:01:42 by rtwitch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CL = client
NAME_SV = server

SRCS_CL = 	client.c \
			utils.c

SRCS_SV	=	server.c \
			utils.c
			
HEADERS = minitalk.h

CC = GCC

FLAGS = -Wall -Wextra -Werror -I.

OBJS_CL		= $(SRCS_CL:.c=.o)
OBJS_SV		= $(SRCS_SV:.c=.o)

RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME_CL) $(NAME_SV)

$(NAME_CL): $(OBJS_CL)
		${CC} $(OBJS_CL) -o $(NAME_CL)

$(NAME_SV): $(OBJS_SV)
		${CC} $(OBJS_SV) -o $(NAME_SV)

%.o:%.c $(HEADERS)
		$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_CL)
	$(RM) $(OBJS_SV)

fclean: clean
	$(RM) $(NAME_CL)
	$(RM) $(NAME_SV)

re: fclean all