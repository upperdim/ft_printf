# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 19:39:51 by tunsal            #+#    #+#              #
#    Updated: 2023/10/23 15:10:13 by tunsal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= ft_printf.c ft_putchar.c ft_putnbr_base.c \
					  ft_putnbr_hex_upcase.c ft_putnbr_hex.c ft_putnbr.c \
					  ft_putstr.c ft_putunbr.c
OBJS				= $(SRCS:.c=.o)

NAME				= libftprintf.a
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror

all:				$(NAME)

$(NAME):			./libft/libft.a $(OBJS)
					cp ./libft/libft.a ./libft.a
					ar rcs $(NAME) $(OBJS)

./libft/libft.a:
					make -C ./libft all

clean:
					make -C ./libft clean
					rm -rf $(OBJS)

fclean:				clean
					make -C ./libft fclean
					rm -rf $(NAME)

re: 				fclean all