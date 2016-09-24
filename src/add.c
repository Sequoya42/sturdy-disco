/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:03:26 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/24 02:28:39 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_add(t_vm *vm , t_proc *p)
{
	int						n1;
	int						n2;

// ft_print(KCYN "OH REALLY !");
	n1 = p->reg[p->set[2]];
	n2 = p->reg[p->set[3]];
	int r = n1 + n2;
	if (r == 0)
		p->carry = 1;
	else
		p->carry = 0;
	p->reg[p->set[4]] = r;
	(void)vm;
}

#if 0

#endif
