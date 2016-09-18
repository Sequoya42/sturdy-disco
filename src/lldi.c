/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:51 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/17 19:56:59 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_lldi(t_vm *vm , t_proc *p)
{
	int						n;
	int						r;

	r = 0;
	n = (p->set[2] + p->set[3]);
	if (n == 0)
		p->carry++;
	n--;
	r |= (VM(n + 1) << 24);
	r |= (VM(n + 2) << 16);
	r |= (VM(n + 3) << 8);
	r |= (VM(n + 4));
	p->reg[p->set[4]] = r;
}