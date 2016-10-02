/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:59 by rbaum             #+#    #+#             */
/*   Updated: 2016/10/01 17:14:11 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_zjmp(t_vm *vm , t_proc *p)
{
	int						n;

	 n = (p->set[1] % IDX_MOD);
	 p->old = p->pc;
	if (p->carry == 1)
	{
		// int k = p->pc + n;
		// if (DEBUG == 1 || vm->cycle->total == 8091)
			// ft_print(KCYN "\t\t\t[%d] Jumping from %d  to : %d\n" KNRM,p->num, p->pc ,k);
		p->pc += n - p->next_i;
	}
	// else
	// 	p->pc += p->next_i;
	// p->pc %= MEM_SIZE;
		// ft_print("old: %d\tpc: %d\tn: %d\n", p->old, p->pc, n);
	// else
	// {
	// 	ft_putendl(KRED "CANNOT JUMP !");
	// }
	(void)vm;
}