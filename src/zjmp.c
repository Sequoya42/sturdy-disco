/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:59 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/18 21:29:32 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_zjmp(t_vm *vm , t_proc *p)
{
	if (p->carry == 1)
	{
		ft_putendl(KCYN "\t\t\tCarrry at one");
		p->pc += p->set[1] % IDX_MOD;
		p->pc %= MEM_SIZE;
	}
	else
	{
		ft_putendl(KRED "CANNOT JUMP !");
	}
	(void)vm;
}