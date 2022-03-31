# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 16:16:21 by jkwak             #+#    #+#              #
#    Updated: 2022/03/31 21:55:05 by jkwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
	   format_char_str.c format_decimal.c format_hexadecimal.c \
	   ft_printf_utils.c

OBJS = ft_printf.o \
	   format_char_str.o format_decimal.o format_hexadecimal.o \
	   ft_printf_utils.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME = libftprintf.a

all : $(NAME)

/*needed to add*/

clean :
		$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
