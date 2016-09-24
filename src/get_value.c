/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 07:57:53 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/24 03:26:18 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						right_value(int r, unsigned int n, t_vm *vm)
{
	// int						j;

	// j = REG_SIZE * 8;
	// n += 3;
	// if (DEBUG == 1)
	// 	ft_print("IN STI : %d\n", r);
	// while (j)
	// {
	// 	VM(n) = (r >> j);
	// 	j -= 8;
	// 	n--;
	// }
	// r = (long)r;
	// ft_print("base : %s\n", ft_base(r, 16));
	VM(n) = (r >> 24) & 0xFF;
	VM(n + 1) = (r >> 16) & 0xFF;
	VM(n + 2) = (r >> 8) & 0xFF;
	VM(n + 3) = (r) & 0xFF;
}


int							get_value(t_proc *p, int i, int j, t_vm *vm)
{
	int 							r;
	int								n;

	r = 0;
	if (p->arg_size[i] == REG_CODE)
		return (p->reg[p->set[j]]);
	else if (p->arg_size[i] == 4)
	{
		n = p->pc + p->set[j] - 1;
		r |= (VM(n + 1) << 24);
		r |= (VM(n + 2) << 16);
		r |= (VM(n + 3) << 8);
		r |= (VM(n + 4));
		// ft_print("Value of r : %d\n", r);
		// ft_print("Value of endian r: %d\n", format_int(r, DIR_SIZE));
		return (r);
	}
	else
		return (p->set[j]);

}
