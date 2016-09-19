/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:11 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/19 09:24:19 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"



void						right_value(int r, int n, t_vm *vm)
{
	int						j;

	j = REG_SIZE * 8;
	n += 3;
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

void						op_st(t_vm *vm , t_proc *p)
{
	int						n;
	int						r;

	n = 0;
	r = (p->arg_size[0] == REG_CODE) ? p->reg[p->set[2]] : p->set[2];
	if (p->arg_size[1] == REG_CODE)
		p->reg[p->set[3]] = r;
	else
	{
		// attron(COLOR_PAIR(-p->num));
		n = p->pc + (p->set[3] % IDX_MOD);
		p->w_st = n;
		right_value(r, n, vm);
		ft_print("ST SUPPOSE TO WRITE SOMETHING [r is %d]  at %d !\n", r, n);
	}
}
