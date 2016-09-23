/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:22 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/23 04:23:44 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void						right_value(int r, unsigned int n, t_vm *vm)
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
	VM(n) = (r >> 24) & 0xFF;
	VM(n + 1) = (r >> 16) & 0xFF;
	VM(n + 2) = (r >> 8) & 0xFF;
	VM(n + 3) = r & 0xFF;
}


static int							get_value(t_proc *p, int i, int j, t_vm *vm)
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

void						op_sti(t_vm *vm , t_proc *p)
{
	int						n;
	int						r;
	int						v1;
	int						v2;

	n = 0;
	r = 0;
	v1 = get_value(p, 1, 3, vm);
	v2 = get_value(p, 2, 4, vm);
	// int k = (v1 + v2);
	// ft_print("Value of k : %d\n", k);
	n = p->pc + ((v1 + v2) % IDX_MOD);
	// ft_print("Value of n %d\n", n);
	r = p->reg[p->set[2]];
	p->w_st = n % MEM_SIZE;
	right_value(r, n, vm);
}


#if 0
CHECK IF ARG IS THIS OR THAT AND ACT IN CONSEQUENCE

#endif