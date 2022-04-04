# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 16:16:21 by jkwak             #+#    #+#              #
#    Updated: 2022/04/05 01:52:04 by jkwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
	   format_char_str.c format_decimal.c format_hexadecimal.c \
	   ft_printf_utils.c

OBJS = ft_printf.o \
	   format_char_str.o format_decimal.o format_hexadecimal.o \
	   ft_printf_utils.o

LIBFT = libft.a
LIBFT_DIR = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT) : $(LIBFT_DIR)
			 cd $(LIBFT_DIR) ; $(MAKE)
			cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)
		make clean -C $(LIBFT_DIR)

fclean : clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT_DIR)

re : fclean $(NAME)

.PHONY : all clean fclean re
