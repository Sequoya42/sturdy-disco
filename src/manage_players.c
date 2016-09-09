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

void						manage_byte_args(int encode, t_vm *vm, t_proc *p)
{
	int						i;
	int						j;

	j = 8;
	i = 1;
	(void)vm;
	encode <<= 2;
	while (j >= 4)
	{
		p->set[i] = (encode >> j) & 3;
		// ft_print(KGRN "\t\t%d\n" KNRM, p->set[i]);
		j -= 2;
		i++;
	}
}

#if 0 
Imnplement pointer function tab to call each of the 16 instructions
Those who need will cann manage byte args
void func (vm, proc)
#endif

int							get_instructions(t_vm *vm, t_proc *p)
{
	int						i;
	int						op;


	i = p->pc;
	op = vm->memory[i];
	p->set[0] = op;
	if (GOT(op).op_mod == 1)
		manage_byte_args(vm->memory[i + 1], vm, p);
		// manage_byte_args(i + 1, op, vm);
	// else
		// manage_args(op, vm);
	p->set[1] = op;
	return (op);
}
#if 0 
Manage "alive" --> cycle alive +=
#endif
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