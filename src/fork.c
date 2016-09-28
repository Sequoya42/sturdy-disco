/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:32 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/29 00:19:16 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


static void					fill_new(t_proc *n, t_proc *p, t_vm *vm)
{
	int						i;

	i = 0;
	n->pc = p->pc + (p->set[1] % IDX_MOD);
	n->pc %= MEM_SIZE;
	n->old = -1;
	n->carry = p->carry;
	n->num = p->num;
	n->alive = p->alive;
	while (i < PROG_NAME_LENGTH)
	{
		if (i <= 16)
			n->reg[i] = p->reg[i];
		n->name[i] = p->name[i];
		i++;
	}
	n->next = NULL;
	n->prev = NULL;
	// ft_putendl("**********\tFORK BEFORE \t*********");
	// test_shit(vm);
	// ft_putendl("**********\tFORK\t*********");
	add_proc(n, vm);
	// test_shit(vm);
	// ft_putendl("**********\tEND_FORK\t*********");
}


#if 0

JUMP TO RIGHT ADRESS WHEN DONE !
#endif

void						op_fork(t_vm *vm , t_proc *p)
{
	t_proc					*n;

	// ft_print(KRED "APPEL A FORK AU CYCLE %d\n" KNRM, vm->cycle->total);
	if (!(n = ft_memalloc(sizeof(t_proc))))
		msg_exit("Bad alloc of new proc [fork]\n");
	fill_new(n, p, vm);
}
