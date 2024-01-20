/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazizi <acazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:25:19 by acazizi           #+#    #+#             */
/*   Updated: 2024/01/20 01:26:59 by acazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(char c, va_list list)
{
	int	len;

	len = 0;
	if (c == '%')
		len = ft_putchar('%');
	else if (c == 'c')
		len = ft_putchar(va_arg(list, int));
	else if (c == 's')
		len = ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(list, int));
	else if (c == 'x')
		len = ft_putnbr_hex(va_arg(list, unsigned int));
	else if (c == 'X')
		len = ft_putnbr_hexx(va_arg(list, unsigned int));
	else if (c == 'u')
		len = ft_putnbr_u(va_arg(list, unsigned int));
	else if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_putnbr_p(va_arg(list, unsigned long));
	}
	return (len);
}
