/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:11 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/23 03:51:35 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int							get_v1(t_proc *p)
{
	if (p->arg_size[0] == REG_CODE)
		return (p->reg[p->set[2]]);
	else
		return (p->set[2]);
}

int							get_v2(t_proc *p)
{
	if (p->arg_size[1] == REG_CODE)
		return (p->reg[p->set[3]]);
	else
		return (p->set[3]);
}

// static int							get_value(t_proc *p, int i, int j)
// {
// 	if (p->arg_size[i] == REG_CODE)
// 		return (p->reg[p->set[j]]);
// 	else if (p->arg_size[i] == IND_CODE)
// 		return (p->set[j] + p->pc);
// 	else
// 		return (p->set[j]);

// }

void						op_ldi(t_vm *vm , t_proc *p)
{
	int						n;
	int						v1;
	int						v2;
	int						r;

	r = 0;
	v1 = get_v1(p);
	v2 = get_v2(p);
	n = p->pc + ((v1 + v2) % IDX_MOD);
	if (n == 0)
		p->carry = 1;
	else
		p->carry = 0;
	n--;
	r |= (VM(n + 1) << 24);
	r |= (VM(n + 2) << 16);
	r |= (VM(n + 3) << 8);
	r |= (VM(n + 4));
	p->reg[p->set[4]] = r;
}

#if 0
	{"ldi", 3, {T_REG | T_DIR | T_IND,
	 			T_DIR | T_REG,
	  			T_REG}

	p->set[2] = t_REG | T_DIR | T_IND
	p->set[3] = T_DIR | T_REG
2 octet

Indirect relatifpc
#endif