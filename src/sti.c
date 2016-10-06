/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:22 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/30 22:34:14 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						sti_visual(unsigned int n, int c, t_vm *vm)
{
	int						j;
	int						k;
	static char				hex[17] = "0123456789abcdef";

	j = -1;
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

void						op_sti(t_vm *vm, t_proc *p)
{
	int						n;
	int						r;
	int						v1;
	int						v2;

	n = 0;
	r = 0;
	v1 = get_value(p, 1, 3, vm);
	v2 = get_value(p, 2, 4, vm);
	n = p->pc + ((v1 + v2) % IDX_MOD);
	r = p->reg[p->set[2]];
	write_value(r, n, vm);
	if (vm->visual == 1)
		sti_visual(n, -p->num, vm);
}
