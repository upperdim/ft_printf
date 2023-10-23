# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 19:39:51 by tunsal            #+#    #+#              #
#    Updated: 2023/10/23 17:36:39 by tunsal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= ft_printf.c ft_putunbr_base.c ft_putnbr.c ft_putstr.c
OBJS				= $(SRCS:.c=.o)

NAME				= libftprintf.a
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror

all:				$(NAME)

$(NAME):			makelibft $(OBJS)
					cp ./libft/libft.a ./$(NAME)
					ar -r $(NAME) $(OBJS)

makelibft:
					make -C ./libft all

clean:
					make -C ./libft clean
					rm -f $(OBJS)

fclean:				clean
					make -C ./libft fclean
					rm -f $(NAME)

re: 				fclean all