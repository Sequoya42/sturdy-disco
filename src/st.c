/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:11 by rbaum             #+#    #+#             */
/*   Updated: 2016/10/01 22:57:08 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						st_visual(unsigned int n, int c, t_vm *vm)
{
	int						j;
	int						k;
	static char				hex[] = "0123456789abcdef";

	j = -1;
	(void)c;
	attron(COLOR_PAIR(c) | A_BOLD);
	while (++j < 4)
	{
		n = M(n);
		move(Y(n), X(n));
		k = VM(n);
		addch(hex[k / 16]);
		addch(hex[k % 16]);
		n++;
	}
	attroff(COLOR_PAIR(c) | A_BOLD);
}

void						op_st(t_vm *vm, t_proc *p)
{
	unsigned int			n;
	int						r;

	n = 0;
	r = p->reg[p->set[2]];
	if (p->arg_size[1] == REG_CODE)
		p->reg[p->set[3]] = r;
	else
	{
		n = p->pc + (p->set[3] % IDX_MOD);
		write_value(r, n, vm);
		if (vm->visual == 1)
			st_visual(n, -p->num, vm);
	}
}
