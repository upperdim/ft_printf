/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:20:53 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/20 17:37:15 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
/*
   TODO:
    - Don't implement the buff management of the original printf.
	- Handle conversions: 
	  %c: print a single char
	  %s: print a string
	  %p: The void * pointer argument has to be printed in hexadecimal format
	  %d: print a decimal (base 10) number
	  %i: print an integer in base 10
	  %u: print an unsigned decimal (base 10) number
	  %x: prints a number in hex lowercase format
	  %X: prints a number in hex uppercase format
	  %%: prints a percent sign
	- Compare against the original printf().
	- Use `ar` to create libftprintf.a at root of repo, NOT `libtool`.

	ft_printf("hello %c there %d\n", )
*/
int	ft_printf(const char *str, ...)
{
	va_list	valist;
	size_t	print_count;
	size_t	curr_placeholder_idx;

	va_start(valist, str);
	curr_placeholder_idx = 0;
	print_count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			++str;
			switch (*str)
			{
				case 'c':
					ft_putchar(va_arg(valist, char));
					++print_count;
					break;
				case 's':
					char *param_str = va_arg(valist, char *);
					ft_putstr(param_str);
					print_count += ft_strlen(param_str);
					break;
				case 'p':
					// TODO
					break;
				case 'd':
				case 'i':
					int param_int = va_arg(valist, char);
					ft_putnbr(param_int);
					print_count += count_digits(param_int);
					break;
				case 'u':
					break;
				case 'x':
					break;
				case 'X':
					break;
				case '%':
					break;
				default:
					// error
					break;
			}
		}
		else
		{
			// write the character
			++print_count;
		}
		++str;		
	}
	return (print_count);
}
