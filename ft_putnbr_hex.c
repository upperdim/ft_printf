/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:05:05 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/22 14:30:10 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

/*
   Write number `n` into standard output in hexadecimal base 
   and return the number of characters printed.
*/
size_t	ft_putnbr_hex(int n)
{
   return (ft_putnbr_base(n, "0123456789abcdef"));
}
