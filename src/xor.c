/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:50 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/27 00:44:18 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_xor(t_vm *vm, t_proc *p)
{
	int						v1;
	int						v2;
	int						n;

	v1 = get_value(p, 0, 2, vm);
	v2 = get_value(p, 1, 3, vm);
	n = (v1 ^ v2);
	p->reg[p->set[4]] = n;
	if (n == 0)
		p->carry = 1;
	else
		p->carry = 0;
	(void)vm;
}
