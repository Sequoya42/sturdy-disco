/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:42 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/30 20:59:19 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


int							get_lld_value(t_proc *p, int i, int j, t_vm *vm)
{
	int 							r;
	int								n;

	r = 0;
	if (p->arg_size[i] == REG_CODE)
		return (p->reg[p->set[j]]);
	else if (p->arg_size[i] == 4)
	{
		n = p->pc + p->set[j];
		r |= (VM(n + 0) << 8);
		r |= (VM(n + 1));
		// ft_print("Value of r : %d\n", r);
		// ft_print("Value of endian r: %d\n", format_int(r, DIR_SIZE));
		return (r);
	}
	else
		return (p->set[j]);
}



void						op_lld(t_vm *vm , t_proc *p)
{
	unsigned int			n;

	n = get_lld_value(p, 0, 2, vm);
	p->reg[p->set[3]] = n;
	if ((n % IDX_MOD) == 0)
		p->carry = 1;
	else
		p->carry = 0;
	(void)vm;
}


#if 0
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
#endif