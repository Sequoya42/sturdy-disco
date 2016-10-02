/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 08:40:39 by rbaum             #+#    #+#             */
/*   Updated: 2016/10/01 23:13:21 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int							get_instructions(t_vm *vm, t_proc *p)
{
	int						i;
	int						op;


	i = p->pc;
	op = VM(i);
	p->set[0] = op;
	if (op > 0 && op < 17)
	{
		put_in_set(i, vm, p);//could move that to verify validity, so get arg at the end
		p->cycle = GOT(op).cycle;
	}
	else
	{
		p->set[0] = 0;
		p->next_i = 1;
		p->cycle = 1;
 	}
	return (1);
}

void						verify_set(int i, t_vm *vm, t_proc *p);
int							verify_validity(t_proc *p, t_vm *vm)
{
	int						i;
	int						j;

	i = 0;
	(void)vm;
	if (put_in_set(p->pc, vm, p) == -1)
		return (0);
	if (p->set[0] < 1 || p->set[0] > 16 || p->arg_size[2] == -1)
		return (0);
	j = GOT(p->set[0]).params;
	while (i < j)
	{
		p->arg_size[i] = p->arg_size[i] == 3 ? 4 : p->arg_size[i];
		if (p->arg_size[i] == 0 || !IS_IN(p->arg_size[i], p->set[0], i))
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

void						tstw(t_proc *p, t_vm *vm)
{
	if (p->cycle == 0)
	{
			if (p->set[0] && verify_validity(p, vm))
				g_operator[p->set[0]](vm, p);
	}
}

void						manage_players(t_cycle *cycle, t_vm *vm)
{
	t_proc					*p;

	p = vm->first;
	(void)cycle;

	while (p)
	{
		if (p->cycle == 0)
		{
			if (p->set[0] && verify_validity(p, vm))
				g_operator[p->set[0]](vm, p);
			else if (p->set[0] == 0)
				p->redo = 1;
			p->old = p->pc;
			p->pc += p->next_i;
			p->pc %= MEM_SIZE;
			get_instructions(vm, p);
		}
		p->cycle--;
		p = p->next;
	}
	p = vm->first;
	while (p)
	{
		if (p->redo == 1)
		{
			get_instructions(vm, p);
			p->cycle--;
			p->redo = 0;
		}
		p = p->next;
	}
}

// void						manage_players(t_cycle *cycle, t_vm *vm)
// {
// 	t_proc					*p;

// 	p = vm->first;
// 	(void)cycle;
// 	while (p)
// 	{
// 		if (p->cycle == 0)
// 		{
// 			if (p->set[0] && verify_validity(p, vm))
// 				g_operator[p->set[0]](vm, p);
// 				p->old = p->pc;
// 				p->pc += p->next_i;
// 				p->pc %= MEM_SIZE;
// 			get_instructions(vm, p);
// 		}
// 		p->cycle--;
// 		p = p->next;
// 	}
// }

#if 0 

get op
if cycle
else if cycle ..
wait cycle

Imnplement pointer function tab to call each of the 16 instructions
Those who need will cann manage byte args
void func (vm, proc)
#endif