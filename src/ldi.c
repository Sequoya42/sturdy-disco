/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:11 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/24 00:44:36 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_ldi(t_vm *vm , t_proc *p)
{
	int						n;
	int						v1;
	int						v2;
	int						r;

	r = 0;
	v1 = get_value(p, 0, 2, vm);
	v2 = get_value(p, 1, 3, vm);
	// ft_print("V1 : %d\tv2\t%d\n", v1, v2);
	n = p->pc + ((v1 + v2));
	n %= MEM_SIZE;
	if (n == 0)
		p->carry = 1;
	else
		p->carry = 0;
	n--;
	r |= (VM(n + 1) << 24);
	r |= (VM(n + 2) << 16);
	r |= (VM(n + 3) << 8);
	r |= (VM(n + 4));
	// ft_print("LDI VALUE OF R %d\n",r);
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