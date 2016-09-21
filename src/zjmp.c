/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:59 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/21 05:05:02 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_zjmp(t_vm *vm , t_proc *p)
{
	if (p->carry == 1)
	{
		// ft_print(KCYN "\t\t\tCarrry at one Jumping from %d  to : %d\n",p->pc ,p->set[1]);

		p->pc += (p->set[1]);
		p->pc %= IDX_MOD;
		p->pc %= MEM_SIZE;
	}
	else
	{
		p->pc += p->next_i;
		p->pc %= MEM_SIZE;
	}
	// else
	// {
	// 	ft_putendl(KRED "CANNOT JUMP !");
	// }
	(void)vm;
}