/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 04:39:19 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/25 16:39:42 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					print_hex_mem(unsigned char *addr)
{
	size_t				i;
	static char			hex[] = "0123456789abcdef";

	i = -1;
	while (++i < 64)
	{
		ft_putchar(hex[(int)addr[i] / 16]);
		ft_putchar(hex[(int)addr[i] % 16]);
		ft_putchar(' ');
	}
}

void					print_raw_mem(unsigned char *addr)
{
	size_t				i;

	i = -1;
	while (++i < 16)
	{
		if (addr[i] > 31 && addr[i] < 127)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
	}
}

void					print_adrr(int i)
{
	unsigned int		j;
	char				*r;

	j = 0;
	r = ft_base(i, 16);
	ft_putstr("0x");
	while (j++ < (4 - ft_strlen(r)))
		ft_putchar('0');
	ft_putstr(r);
	ft_putstr(" : ");
}

void					print_memory(const void *addr, size_t size)
{
	size_t			i;

	i = 0;
	while (size >= 64)
	{
		print_adrr(i);
		print_hex_mem((unsigned char*)(addr + i));
		ft_putchar('\n');
		size -= 64;
		i += 64;
	}
}
