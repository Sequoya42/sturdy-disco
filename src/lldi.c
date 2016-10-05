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

void						op_lldi(t_vm *vm , t_proc *p)
{
	unsigned int			n;
	int						v1;
	int						v2;
	int						r;

	r = 0;
	v1 = get_value(p, 0, 2, vm);
	v2 = get_value(p, 1, 3, vm);
	#if 0
	p->pc?
	#endif
	n = p->pc + ((v1 + v2));
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
