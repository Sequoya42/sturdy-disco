/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:11 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/24 19:24:02 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						st_visual(unsigned int n, int c, t_vm *vm)
{
	int						j;
	int						k;
	char					hex[] = "0123456789abcdef";


	j = -1;
	attron(COLOR_PAIR(c));
	while (++j < 4)
	{
		n = M(n);
		move((n / 64) + 4, (n % 64) * 3);
		k = VM(n);
		addch(hex[k / 16]);
		addch(hex[k % 16]);
		n++;
}
	attroff(COLOR_PAIR(c));
}

void						op_st(t_vm *vm , t_proc *p)
{
	unsigned int			n;
	int						r;

	n = 0;
	r = (p->arg_size[0] == REG_CODE) ? p->reg[p->set[2]] : p->set[2];
	if (p->arg_size[1] == REG_CODE)
		p->reg[p->set[3]] = r;
	else
	{
		n = p->pc + (p->set[3] % IDX_MOD);
		p->w_st = n % MEM_SIZE;
		right_value(r, n, vm);
		if (vm->visual == 1)
			st_visual(n, -p->num, vm);
	}
}
