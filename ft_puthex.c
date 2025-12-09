/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:41:44 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/09 14:42:14 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(unsigned int n, char *base)
{
	int		len;
	int		i;
	int		tmp;
	char	str[9];

	len = 0;
	i = 0;
	while (n != 0)
	{
		str[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		tmp = ft_putchar_fd_l(str[i], 1);
		if (tmp < 0)
			return (-1);
		len += tmp;
		i--;
	}
	return (len);
}

int	ft_puthex(unsigned int n, char c)
{
	int		len;
	char	base[17];

	if (c == 'x')
		ft_strlcpy(base, "0123456789abcdef", 17);
	else if (c == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	else
	{
		ft_strlcpy(base, "", 1);
		return (-1);
	}
	if (n == 0)
	{
		len = ft_putchar_fd_l('0', 1);
		if (len < 0)
			return (-1);
		return (len);
	}
	len = print_hex(n, base);
	return (len);
}
