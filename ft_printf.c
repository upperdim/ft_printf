/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:20:53 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/23 18:14:27 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

#define SUCCESS 0
#define FAILURE -1

/*
   Handle symbols and update number of characters printed to the screen 
   via `p_printed_cnt` parameter.
   Return 0 (defined as SUCCESS) if no errors, else -1 (defined as FAILURE).
*/
static int	handle_symbols(const char *fmt, va_list *valist, int *p_printed_cnt)
{
	if (*fmt == 'c')
		*p_printed_cnt += ft_putchar(va_arg(*valist, int));
	else if (*fmt == 's')
		*p_printed_cnt += ft_putstr(va_arg(*valist, char *));
	else if (*fmt == 'p')
		*p_printed_cnt += ft_putunbr_ptr(va_arg(*valist, size_t), 1);
	else if (*fmt == 'd' || *fmt == 'i')
		*p_printed_cnt += ft_putnbr(va_arg(*valist, int));
	else if (*fmt == 'u')
		*p_printed_cnt += ft_putunbr(va_arg(*valist, unsigned int));
	else if (*fmt == 'x')
		*p_printed_cnt += ft_putunbr_hex(va_arg(*valist, unsigned int), 0);
	else if (*fmt == 'X')
		*p_printed_cnt += ft_putunbr_hex(va_arg(*valist, unsigned int), 1);
	else if (*fmt == '%')
		*p_printed_cnt += ft_putchar('%');
	else
		return (FAILURE);
	return (SUCCESS);
}

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
int	ft_printf(const char *fmt, ...)
{
	va_list	valist;
	int		print_count;

	if (fmt == NULL)
		return (-1);
	va_start(valist, fmt);
	print_count = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			if (handle_symbols(++fmt, &valist, &print_count) == FAILURE)
				return (-1);
		}
		else
			print_count += ft_putchar(*fmt);
		++fmt;
	}
	va_end(valist);
	return (print_count);
}
