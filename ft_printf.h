/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:05:53 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/09 13:42:31 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

int		ft_putchar_fd_l(char c, int fd);
int		ft_putstr_fd_l(char *s, int fd);
int		ft_putnbr_fd_l(int n, int fd);
int		ft_putptr(unsigned long address);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned int n, char c);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
