/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:05:10 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/23 17:32:54 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

/*
   Write character `c` into standard output
   and return number of characters printed on the screen.
*/
size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/*
   Print a string to the standard out and return number of characters printed.
   Print "(null)" and return 6 if the string is NULL.
*/
size_t	ft_putstr(char *s)
{
	size_t	s_len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	s_len = ft_strlen(s);
	write(1, s, s_len);
	return (s_len);
}
