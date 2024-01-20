/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazizi <acazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:38:24 by acazizi           #+#    #+#             */
/*   Updated: 2024/01/20 01:26:19 by acazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s == NULL)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	while (s[i] != '\0')
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_putnbr_hex(unsigned int n)
{
	char	*tab;
	int		len;

	len = 0;
	tab = "0123456789abcdef";
	if (n >= 16)
	{
		len += ft_putnbr_hex(n / 16);
		len += ft_putnbr_hex(n % 16);
	}
	else
		len += ft_putchar(tab[n]);
	return (len);
}

int	ft_putnbr_hexx(unsigned int n)
{
	char	*tab;
	int		len;

	len = 0;
	tab = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_putnbr_hexx(n / 16);
		len += ft_putnbr_hexx(n % 16);
	}
	else
		len += ft_putchar(tab[n]);
	return (len);
}

int	ft_putnbr_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putnbr_u(n / 10);
		len += ft_putnbr_u(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	size_t	i;
	int		len;

	len = 0;
	va_start(list, str);
	i = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			len += ft_print(str[i], list);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (len);
}
