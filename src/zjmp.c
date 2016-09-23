/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:59 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/22 18:16:01 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_zjmp(t_vm *vm , t_proc *p)
{
	int						n;

	 n = p->set[1] % IDX_MOD;
	if (p->carry == 1)
	{
		int k = p->pc + n;
		if (DEBUG == 1)
			ft_print(KCYN "\t\t\t[%d] Jumping from %d  to : %d\n",p->num, p->pc ,k);
		p->pc += n;
	}
	else
		p->pc += p->next_i;
	p->pc %= MEM_SIZE;
	// else
	// {
	// 	ft_putendl(KRED "CANNOT JUMP !");
	// }
	(void)vm;
}