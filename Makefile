# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 14:52:38 by elvmarti          #+#    #+#              #
#    Updated: 2021/11/13 19:51:04 by elvmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

NAME_CLIENT = client

HEADER = includes/minitalk.h

SRCS_SERVER = srcs/server.c \
			srcs/aux.c

SRCS_CLIENT = srcs/client.c \
			srcs/aux.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

$(NAME): $(OBJS_CLIENT) $(OBJS_SERVER)
		$(CC) ${CFLAGS} ${SRCS_SERVER} -I $(HEADER) -L. -o $(NAME) 
		$(CC) ${CFLAGS} ${SRCS_CLIENT} -I $(HEADER) -L. -o $(NAME_CLIENT)

all: $(NAME)

clean:
		$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
		$(RM) $(NAME) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re