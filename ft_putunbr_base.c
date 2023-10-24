/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:39:33 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/24 16:27:10 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

/*
 * Longest string is when the base is 2. 8 byte size_t has 64 bits.
 * Size can be 64 digits long. + 1 for '\0'.
 */
#define BUFF_SIZE 65

/*
 * base_dig_count: 10 for decimal (base-10), 16 for hex (base-16) etc.
 */
static int	count_num_digits_base(size_t nb, int base_dig_count)
{
	int	digit_count;

	if (nb == 0)
		return (1);
	digit_count = 0;
	while (nb != 0)
	{
		nb /= base_dig_count;
		++digit_count;
	}
	return (digit_count);
}

static int	is_valid_base(char *base, int len)
{
	int	i;
	int	j;

	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (base[i] < ' ' || base[i] == 127 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
			if (base[i] == base[j++])
				return (0);
		++i;
	}
	return (1);
}

/*
   Print decimal size `nbr` in given base `base`. `base` consists of
   all the digits in that base.
   For example, `base` would be "0123456789abcdef" for hex.

   Return number of characters printed on the screen.
   Return -1 if ft_putstr fails or upon any error.
*/
int	ft_putsize_base(size_t nbr, char *base)
{
	char	buff[BUFF_SIZE];
	int		buff_idx;
	int		base_len;
	size_t	printed_count;
	size_t	num_len;

	base_len = ft_strlen(base);
	if (!is_valid_base(base, base_len))
		return (0);
	buff_idx = count_num_digits_base(nbr, base_len);
	buff[0] = base[0];
	buff[buff_idx--] = '\0';
	while (nbr > 0)
	{
		buff[buff_idx--] = base[(nbr % base_len)];
		nbr /= base_len;
	}
	num_len = ft_strlen(buff);
	printed_count = ft_putstr(buff);
	if (num_len != printed_count)
		return (-1);
	return (printed_count);
}

/*
   Write number `n` into standard output in hexadecimal base 
   and return the number of characters printed.
   Return -1 if ft_putsize_base fails or upon any error.

   Uppercase hexadecimal notation will be used if `use_uppercase_notation`
   flag is true.
*/
int	ft_putunbr_hex(unsigned int n, int use_uppercase_notation)
{
	if (use_uppercase_notation)
		return (ft_putsize_base((size_t) n, "0123456789ABCDEF"));
	else
		return (ft_putsize_base((size_t) n, "0123456789abcdef"));
}

/*
   Write number `n` into standard output in hexadecimal base 
   and return the number of characters printed.
   Return -1 if ft_putstr fails or upon any error.

   Prefix "0x" to the number if `use_hex_prefix` is true.
*/
int	ft_putunbr_ptr(size_t addr, int use_hex_prefix)
{
	int	printed_count;
	int	ret;

	printed_count = 0;
	if (use_hex_prefix)
	{
		ret = ft_putstr("0x");
		if (ret != 2)
			return (-1);
		printed_count += ret;
	}
	ret = ft_putsize_base(addr, "0123456789abcdef");
	if (ret < 0)
		return (-1);
	printed_count += ret;
	return (printed_count);
}
