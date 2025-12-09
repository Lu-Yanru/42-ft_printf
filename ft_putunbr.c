/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:41:44 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/08 16:27:25 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	if (n > 9)
	{
		if (ft_putunbr(n / 10) < 0)
			return (-1);
		if (ft_putunbr(n % 10) < 0)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd_l(n + '0', 1) < 0)
			return (-1);
	}
	return (numlen(n));
}
