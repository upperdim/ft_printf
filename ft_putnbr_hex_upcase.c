/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_upcase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:05:02 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/22 14:30:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

/*
   Write number `n` into standard output in uppercase notation hexadecimal base 
   and return the number of characters printed.
*/
size_t	ft_putnbr_hex_upcase(int n)
{
   return (ft_putnbr_base(n, "0123456789ABCDEF"));
}
