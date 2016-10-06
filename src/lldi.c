/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:51 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/26 19:33:48 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int							get_lldi_value(t_proc *p, int i, int j, t_vm *vm)
{
	int						r;
	unsigned int			n;

	r = 0;
	if (p->arg_size[i] == REG_CODE)
		return (p->reg[p->set[j]]);
	else if (p->arg_size[i] == 4)
	{
		n = p->pc + p->set[j];
		r |= (VM(n + 0) << 24);
		r |= (VM(n + 1) << 16);
		r |= (VM(n + 2) << 8);
		r |= (VM(n + 3));
		return (r);
	}
	else
		return (p->set[j]);
}

void						op_lldi(t_vm *vm, t_proc *p)
{
	unsigned int			n;
	int						v1;
	int						v2;
	int						r;

	r = 0;
	v1 = get_lldi_value(p, 0, 2, vm);
	v2 = get_lldi_value(p, 1, 3, vm);
	n = p->pc + ((v1 + v2));
	n %= MEM_SIZE;
	r |= (VM(n + 0) << 24);
	r |= (VM(n + 1) << 16);
	r |= (VM(n + 2) << 8);
	r |= (VM(n + 3));
	if (!r)
		p->carry = 1;
	else
		p->carry = 0;
	p->reg[p->set[4]] = r;
}
