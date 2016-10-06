/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:02 by rbaum             #+#    #+#             */
/*   Updated: 2016/10/01 17:48:59 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int							get_ld_value(t_proc *p, int i, int j, t_vm *vm)
{
	int						r;
	int						n;

	r = 0;
	if (p->arg_size[i] == REG_CODE)
		return (p->reg[p->set[j]]);
	else if (p->arg_size[i] == 4)
	{
		n = p->pc + (p->set[j] % IDX_MOD);
		r |= (VM(n + 0) << 24);
		r |= (VM(n + 1) << 16);
		r |= (VM(n + 2) << 8);
		r |= (VM(n + 3));
		return (r);
	}
	else
		return (p->set[j]);
}

void						op_ld(t_vm *vm, t_proc *p)
{
	unsigned int			n;

	n = get_ld_value(p, 0, 2, vm);
	p->reg[p->set[3]] = n;
	if (n == 0)
		p->carry = 1;
	else
		p->carry = 0;
	(void)vm;
}
