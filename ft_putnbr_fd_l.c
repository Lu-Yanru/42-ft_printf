/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:41:44 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/08 16:16:34 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_fd_l(int n, int fd)
{
	if (n == -2147483648)
	{
		if (ft_putstr_fd_l("-2147483648", fd) < 0)
			return (-1);
	}
	else if (n < 0)
	{
		if (ft_putchar_fd_l('-', fd) < 0)
			return (-1);
		if (ft_putnbr_fd_l(-n, fd) < 0)
			return (-1);
	}
	else if (n > 9)
	{
		if (ft_putnbr_fd_l(n / 10, fd) < 0)
			return (-1);
		if (ft_putnbr_fd_l(n % 10, fd) < 0)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd_l(n + '0', fd) < 0)
			return (-1);
	}
	return (numlen(n));
}
