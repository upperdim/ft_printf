/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:39:41 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/23 17:46:15 by tunsal           ###   ########.fr       */
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
size_t	ft_putunbr_base(unsigned int nbr, char *base);
size_t	ft_putunbr_hex(unsigned int n);
size_t	ft_putunbr_hex_upcase(unsigned int n);

#endif