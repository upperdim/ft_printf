/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:20:53 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/22 14:03:24 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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
					print_count += ft_putstr(param_str);
					break;
				case 'p':
					// Take the (void *) argument whose value holds an address
					// Print its value (address) in hex format
					break;
				case 'd':
				case 'i':
					int param_int = va_arg(valist, char);
					print_count += ft_putnbr(param_int);
					break;
				case 'u':
					// Get the number whether dec, oct or hex
					// Without modifying it, interpret its bits as base 10 unsigned decimal
					// Print it
					unsigned int param_uint = va_arg(valist, int);
					print_count += ft_putnbr(param_uint);
					break;
				case 'x':
					int param_int = va_arg(valist, int);
					print_count += ft_putnbr_hex(param_int);
					break;
				case 'X':
					int param_int = va_arg(valist, int);
					print_count += ft_putnbr_hex_upcase(param_int);
					break;
				case '%':
					ft_putchar('%');
					++print_count;
					break;
				default:
					return (-1);
			}
		}
		else
		{
			ft_putchar(*str);
			++print_count;
		}
		++str;		
	}
	va_end(valist);
	return (print_count);
}
