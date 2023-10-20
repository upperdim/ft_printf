# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 19:39:51 by tunsal            #+#    #+#              #
#    Updated: 2023/10/20 19:54:23 by tunsal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c
OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
RM			= rm -f

all:		$(NAME)

$(NAME):	./libft/libft.a $(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
	$(RM) $(NAME)

re: 		fclean all