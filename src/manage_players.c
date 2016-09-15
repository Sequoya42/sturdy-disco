/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 08:40:39 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/04 08:40:44 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int							get_instructions(t_vm *vm, t_proc *p)
{
	int						i;
	int						op;


	i = p->pc;
	op = vm->memory[i];
	// ft_print("OP HERE INSTRUCT \t\t%d\n", op);
	p->set[0] = op;
	if (op > 0 && op < 17)
	{
		put_in_set(i, vm, p);
		p->cycle = GOT(op).cycle;
	}
	else
	{
		p->pc++;
		p->cycle = 0;
	}
	// ft_print("pc: %d\t\tcycle:\t%d\n", p->pc, p->cycle);
	return (op);
}

void						manage_players(t_cycle *cycle, t_vm *vm)
{
	t_proc					*p;

	p = vm->first;
	(void)cycle;
	while (p)
	{
		if (p->cycle == 0)
			get_instructions(vm, p);
		else
			p->cycle--;
		p = p->next;
	}
}

#if 0 

get op
if cycle
else if cycle ..
wait cycle

Imnplement pointer function tab to call each of the 16 instructions
Those who need will cann manage byte args
void func (vm, proc)

static t_fptr       	g_operator[CODE_LEN] =
{
    NULL,
    &op_live,
    &op_ld,
    &op_st,
    &op_add,
    &op_sub,
    &op_and,
    &op_or,
    &op_xor,
    &op_zjmp,
    &op_ldi,
    &op_sti,
    &op_fork,
    &op_lld,
    &op_lldi,
    &op_lfork,
    &op_aff
};
#endif