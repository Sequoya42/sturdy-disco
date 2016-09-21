/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:22 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/21 04:58:51 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void						right_value(int r, unsigned int n, t_vm *vm)
{
	int						j;

	j = REG_SIZE * 8;
	n += 3;
	if (DEBUG == 1)
		ft_print("IN STI : %d\n", r);
	while (j)
	{
		VM(n) = (r >> j);
		j -= 8;
		n--;
	}
	// VM(n) = (r >> 24) & 0xFF;
	// VM(n + 1) = (r >> 16) & 0xFF;
	// VM(n + 2) = (r >> 8) & 0xFF;
	// VM(n + 3) = r & 0xFF;
}

void						op_sti(t_vm *vm , t_proc *p)
{
	int						n;
	int						r;

	n = 0;
	r = 0;
	n = p->pc + ((p->set[3] + p->set[4]) % IDX_MOD);
	r = p->reg[p->set[2]];
	p->w_st = n % MEM_SIZE;
	right_value(r, n, vm);
}


#if 0


#endif