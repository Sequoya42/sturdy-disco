/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:22 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/29 02:01:16 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						sti_visual(unsigned int n, int c, t_vm *vm)
{
	int						j;
	int						k;
	char					hex[] = "0123456789abcdef";

	j = -1;
	attron(COLOR_PAIR(c) | A_BOLD);
	while (++j < 4)
	{
		n = M(n);
		move((n / 64) + 4, (n % 64) * 3);
		k = VM(n);
		addch(hex[k / 16]);
		addch(hex[k % 16]);
		n++;
	}
	attroff(COLOR_PAIR(c) | A_BOLD);
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
	// ft_print("%d\t%d\n", v1, v2);
	n = p->pc + ((v1 + v2) % IDX_MOD);
	r = p->reg[p->set[2]];
	right_value(r, n, vm);
	if (vm->visual == 1)
		sti_visual(n, -p->num, vm);
}


#if 0
CHECK IF ARG IS THIS OR THAT AND ACT IN CONSEQUENCE

#endif