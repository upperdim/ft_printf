/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:05:07 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/05 16:47:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
   Longest integer we can receive is -2147483647 with length 11.
   We need 12 characters including the null-terminator.
*/
#define BUFF_SIZE 12

static int	count_digits(int nb)
{
	int	digit_count;

	if (nb == 0)
		return (1);
	digit_count = 0;
	while (nb != 0)
	{
		nb /= 10;
		++digit_count;
	}
	return (digit_count);
}

/*
   Print a number to the standard out and return number of characters printed.
   Return -1 if write fails or upon any error.
*/
int	ft_putnbr(int nb)
{
	char	buff[BUFF_SIZE];
	int		buff_idx;
	ssize_t	ret;

	if (nb >= 0)
	{
		buff_idx = count_digits(nb);
		buff[0] = '0';
		nb = -nb;
	}
	else
	{
		buff_idx = count_digits(nb) + 1;
		buff[0] = '-';
	}
	buff[buff_idx--] = '\0';
	while (nb < 0)
	{
		buff[buff_idx--] = '0' + -(nb % 10);
		nb /= 10;
	}
	ret = write(1, buff, ft_strlen(buff));
	if (ret != (ssize_t) ft_strlen(buff))
		return (-1);
	return (ret);
}
