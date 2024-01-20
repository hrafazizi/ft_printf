/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazizi <acazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:08:03 by acazizi           #+#    #+#             */
/*   Updated: 2024/01/19 22:31:00 by acazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_putnbr_p(unsigned long n)
{
	int		len;
	char	*tab;

	len = 0;
	tab = "0123456789abcdef";
	if (n >= 16)
	{
		len += ft_putnbr_p(n / 16);
		len += ft_putnbr_p(n % 16);
	}
	else
		len += ft_putchar(tab[n]);
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len = write(1, "-2147483648", 11);
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n = n * (-1);
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}
