/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 08:40:39 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/21 04:50:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#if 0
Verify validity of the args
could do something like 

#endif

int							get_instructions(t_vm *vm, t_proc *p)
{
	int						i;
	int						op;


	i = p->pc;
	op = VM(i);
	p->set[0] = op;
	if (op > 0 && op < 17)
	{
		put_in_set(i, vm, p);
		p->cycle = GOT(op).cycle;
	}
	else
		p->pc++;
	return (1);
}

int							verify_validity(t_proc *p)
{
	int						i;
	int						j;

	i = 0;
	if (p->set[0] < 1 || p->set[0] > 17)
		return (0);
	j = GOT(p->set[0]).params;
	//le if suivant n'a aucun sens
	if (j < 1 || j > 17)
		return (0);
	while (i < j)
	{
		p->arg_size[i] = p->arg_size[i] == 3 ? 4 : p->arg_size[i];
		if (!IS_IN(p->arg_size[i], p->set[0], i) || p->arg_size[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

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

void						manage_players(t_cycle *cycle, t_vm *vm)
{
	t_proc					*p;

	p = vm->first;
	(void)cycle;
	while (p)
	{
		if (p->cycle == 0)
		{
			if (verify_validity(p))
			{
				g_operator[p->set[0]](vm, p);
				if (p->set[0] != 9)
				{
					p->pc += p->next_i;
					p->pc %= MEM_SIZE;
				}

			}
			get_instructions(vm, p);
		}
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
#endif