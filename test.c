/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:11:36 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/09 17:32:31 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int	main(void)
{
	char	c = 'c';
	char	str[] = "Hello World!.;";
	void	*ptr = &c;
	int		num10 = -2147483648;
	int		numi = 2147483647;
	unsigned int	numu = 4294967295;
	unsigned int		numhex = 42949672;
	unsigned int		numHEX = 4294967295;
	int		res1;
	int		res2;
	int		res3;
	int		res4;

	res1 = printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", c, str, ptr, num10, numi, numu, numhex, numHEX);
	printf("res printf: %i\n", res1);
	printf("========================\n");
	res2 = ft_printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", c, str, ptr, num10, numi, numu, numhex, numHEX);
	printf("res mine: %i\n", res2);
	printf("=========== Some more edge cases ===========\n");
	res3 = printf("%s\n", (char *)NULL);
	printf("res printf: %i\n", res3);
	res4 = ft_printf("%s\n", (char *)NULL);
	printf("res mine: %i\n", res4);
	printf("==========\n");
	int	res5 = printf("%p\n", (void *)0);
	printf("res printf: %i\n", res5);
	int	res6 = ft_printf("%p\n", (void *)0);
	printf("res mine: %i\n", res6);
	printf("==========\n");
	int	res7 = printf("%s\n", "");
	printf("res printf: %i\n", res7);
	int	res8 = ft_printf("%s\n", "");
	printf("res mine: %i\n", res8);
}
