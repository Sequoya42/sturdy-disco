/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:30:47 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/22 18:22:45 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int				ft_endian(unsigned int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}

unsigned int				ft_swap(unsigned int val)
{
	return ((val << 8) | (val >> 8));
}

int							format_int(int n, int size)
{
	int							y;

	if (n < 0)
	{
		y = (~n) + 1;
		n = size == T_DIR ? 0x10000 - y : -y;
	}
	if (size == IND_SIZE)
		n = ft_swap(n);
	else if (size == DIR_SIZE)
		n = ft_endian(n);
	return (n);
}
