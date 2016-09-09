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

void						get_args_size(int encode, t_proc *p)
{
	int						i;
	int						j;

	j = 8;
	i = 0;
	encode <<= 2;
	while (j >= 4)
	{
		p->arg_size[i] = (encode >> j) & 3;
		j -= 2;
		i++;
	}
}

int							get_instructions(t_vm *vm, t_proc *p)
{
	int						i;
	int						op;


	i = p->pc;
	op = vm->memory[i];
	p->set[0] = op;
	if (GOT(op).op_mod == 1)
		get_args_size(vm->memory[i + 1], p);

	p->set[1] = op;
	return (op);
}

void						manage_players(t_cycle *cycle, t_vm *vm)
{
	unsigned int			i;
	t_proc					*p;

	i = -1;
	p = vm->first;
	(void)cycle;
	while (++i < vm->nb_champ)
	{
			get_instructions(vm, p);
			p = p->next;
	}
}

#if 0 
Imnplement pointer function tab to call each of the 16 instructions
Those who need will cann manage byte args
void func (vm, proc)

static t_fptr       	g_operator[CODE_LEN] =
{
    NULL,
    &live,
    &ld,
    &st,
    &add,
    &sub,
    &and,
    &or,
    &xor,
    &zjmp,
    &ldi,
    &sti,
    &fork,
    &lld,
    &lldi,
    &lfork,
    &aff
};
#endif