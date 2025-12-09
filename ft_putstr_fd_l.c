/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:27:52 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/09 16:32:23 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_l(char *s, int fd)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	if (!s)
		return (ft_putstr_fd_l("(null)", 1));
	while (s[i])
	{
		tmp = ft_putchar_fd_l(s[i], fd);
		if (tmp < 0)
			return (-1);
		len += tmp;
		i++;
	}
	return (len);
}
