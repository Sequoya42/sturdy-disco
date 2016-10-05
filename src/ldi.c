/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:11 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/26 17:58:05 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_ldi(t_vm *vm , t_proc *p)
{
	unsigned int			n;
	int						v1;
	int						v2;
	int						r;

	r = 0;
	v1 = get_value(p, 0, 2, vm);
	v2 = get_value(p, 1, 3, vm);
	n = p->pc + ((v1 + v2) % IDX_MOD);
	r |= (VM(n + 0) << 24);
	r |= (VM(n + 1) << 16);
	r |= (VM(n + 2) << 8);
	r |= (VM(n + 3));
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