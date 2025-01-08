# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsamy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 12:13:56 by bsamy             #+#    #+#              #
#    Updated: 2024/12/18 12:14:00 by bsamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c ft_printf_number_hex.c\
		ft_printf_ptr.c ft_printf_unsigned_int.c \
		ft_printf_int_decimal.c
		
OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
LIBC = ar -rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

%.o: %.c ft_printf.h Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
