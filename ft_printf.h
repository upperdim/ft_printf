/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:39:41 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/23 18:08:02 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *fmt, ...);

size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);

size_t	ft_putnbr(int nb);
size_t	ft_putunbr(unsigned int nb);
size_t	ft_putunbr_base(size_t nbr, char *base);
size_t	ft_putunbr_hex(unsigned int n, int use_uppercase_notation);
size_t	ft_putunbr_ptr(size_t addr, int use_hex_prefix);

#endif