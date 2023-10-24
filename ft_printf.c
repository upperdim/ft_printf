/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:20:53 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/24 16:49:26 by tunsal           ###   ########.fr       */
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
	int	ret;

	if (*fmt == 'c')
		ret = ft_putchar((char) va_arg(*valist, int));
	else if (*fmt == 's')
		ret = ft_putstr(va_arg(*valist, char *));
	else if (*fmt == 'p')
		ret = ft_putunbr_ptr(va_arg(*valist, size_t), 1);
	else if (*fmt == 'd' || *fmt == 'i')
		ret = ft_putnbr(va_arg(*valist, int));
	else if (*fmt == 'u')
		ret = ft_putunbr(va_arg(*valist, unsigned int));
	else if (*fmt == 'x')
		ret = ft_putunbr_hex(va_arg(*valist, unsigned int), 0);
	else if (*fmt == 'X')
		ret = ft_putunbr_hex(va_arg(*valist, unsigned int), 1);
	else if (*fmt == '%')
		ret = ft_putchar('%');
	else
		return (FAILURE);
	if (ret < 0)
		return (FAILURE);
	*p_printed_cnt += ret;
	return (SUCCESS);
}

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
		{
			if (ft_putchar(*fmt) != 1)
				return (-1);
			print_count += 1;
		}
		++fmt;
	}
	va_end(valist);
	return (print_count);
}
