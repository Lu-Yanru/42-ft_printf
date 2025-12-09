/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:41:44 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/09 14:35:59 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(unsigned long n, char *base)
{
	int		len;
	int		i;
	int		tmp;
	char	str[17];

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

int	ft_putptr(unsigned long address)
{
	int		len;
	int		tmp;
	char	base[17];

	len = 0;
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (address == 0)
		return (ft_putstr_fd_l("(nil)", 1));
	tmp = ft_putstr_fd_l("0x", 1);
	if (tmp < 0)
		return (-1);
	len += tmp;
	tmp = print_hex(address, base);
	if (tmp < 0)
		return (-1);
	len += tmp;
	return (len);
}
