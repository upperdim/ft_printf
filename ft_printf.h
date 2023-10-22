#ifndef FT_PRINTF
# define FT_PRINT

#include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_putnbr(int nb);

size_t	ft_putnbr_base(int nbr, char *base);
size_t	ft_putnbr_hex(int n);
size_t	ft_putnbr_hex_upcase(int n);

#endif