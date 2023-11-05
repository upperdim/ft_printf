/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:05:10 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/05 16:46:27 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
   Print a string to the standard out and return number of characters printed.
   Print "(null)" and return 6 if the string is NULL.

   Return -1 if write fails or upon any error.
*/
int	ft_putstr(char *s)
{
	ssize_t	ret;
	size_t	s_len;

	if (s == NULL)
	{
		ret = write(1, "(null)", 6);
		if (ret != 6)
			return (-1);
		return (ret);
	}
	s_len = ft_strlen(s);
	ret = write(1, s, s_len);
	if (ret != (ssize_t) s_len)
		return (-1);
	return (ret);
}
