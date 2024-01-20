/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazizi <acazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:38:49 by acazizi           #+#    #+#             */
/*   Updated: 2024/01/14 16:39:14 by acazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_putnbr_p(unsigned long n);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putnbr_hex(unsigned int n);
int	ft_putnbr_hexx(unsigned int n);
int	ft_putnbr_u(unsigned int n);
int	ft_print(char c, va_list list);

#endif