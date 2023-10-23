/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:05:07 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/23 14:43:24 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

/* 
   Longest integer we can receive is 4294967295 with length 10.
   We need 11 characters including the null-terminator.
*/
#define BUFF_SIZE 11

static int	count_digits(unsigned int nb)
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
   Print an unsigned number to the standard out 
   and return number of characters printed.
*/
size_t	ft_putunbr(unsigned int nb)
{
	char	buff[BUFF_SIZE];
	int		buff_idx;
	size_t	num_len;

	buff[0] = '0';
	buff_idx = count_digits(nb);
	buff[buff_idx--] = '\0';
	while (nb > 0)
	{
		buff[buff_idx] = '0' + (nb % 10);
		nb /= 10;
		--buff_idx;
	}
	num_len = ft_strlen(buff);
	write(1, buff, num_len);
	return (num_len);
}
