#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *fmt, ...);

size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);

size_t	ft_putnbr(int nb);
size_t	ft_putunbr(unsigned int nb);
size_t	ft_putunbr_base(unsigned int nbr, char *base);
size_t	ft_putunbr_hex(unsigned int n);
size_t	ft_putunbr_hex_upcase(unsigned int n);

#endif