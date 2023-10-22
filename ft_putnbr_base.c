#include "libft/libft.h"
#include "ft_printf.h"

/*
 * Longest string is when the base is 2. 4 byte integer has 32 bits.
 * For positive, number can be 32 digits long. + 1 for '\0'.
 * For negative, number can be 31 digits long. + 2 for '-' and '\0'.
 */
#define BUFF_SIZE 33

/*
 * base_dig_count: 10 for decimal (base-10), 16 for hex (base-16) etc.
 */
static int	count_num_digits_base(int nb, int base_dig_count)
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
   Print decimal number `nbr` in given base `base`. `base` consists of
   all the digits of that base.
   For example, `base` would be "0123456789abcdef" for hex.

   Return number of characters printed on the screen.
*/
size_t	ft_putnbr_base(int nbr, char *base)
{
	char	buff[BUFF_SIZE];
	int		buff_idx;
	int		base_len;
	size_t	printed_count;

	base_len = ft_strlen(base);
	if (!is_valid_base(base, base_len))
		return ;
	if (nbr >= 0)
	{
		buff_idx = count_num_digits_base(nbr, base_len);
		buff[0] = base[0];
		nbr = -nbr;
	}
	else
	{
		buff_idx = count_num_digits_base(nbr, base_len) + 1;
		buff[0] = '-';
	}
	buff[buff_idx--] = '\0';
	while (nbr < 0)
	{
		buff[buff_idx--] = base[-(nbr % base_len)];
		nbr /= base_len;
	}
	printed_count = ft_putstr(buff);
	return (printed_count);
}
