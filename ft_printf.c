/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:07:11 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/09 16:59:57 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

static int	check_conversion(char c, va_list args)
{
	int	tmp;

	if (c == 'c')
		tmp = ft_putchar_fd_l(va_arg(args, int), 1);
	else if (c == 's')
		tmp = ft_putstr_fd_l(va_arg(args, char *), 1);
	else if (c == 'p')
		tmp = ft_putptr(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		tmp = ft_putnbr_fd_l(va_arg(args, int), 1);
	else if (c == 'u')
		tmp = ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		tmp = ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		tmp = ft_putchar_fd_l('%', 1);
	else
		return (-1);
	return (tmp);
}

static int	process_format(const char *format, va_list args, int *len)
{
	int	i;
	int	tmp;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && is_conversion(format[i + 1]) != 0)
		{
			tmp = check_conversion(format[i + 1], args);
			if (tmp < 0)
				return (-1);
			*len += tmp;
			i += 2;
		}
		else
		{
			tmp = ft_putchar_fd_l(format[i], 1);
			if (tmp < 0)
				return (-1);
			*len += tmp;
			i++;
		}
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	if (process_format(format, args, &len) < 0)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (len);
}
