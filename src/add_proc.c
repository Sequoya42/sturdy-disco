/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 03:49:22 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/24 05:06:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// Implement prev
void					add_proc(t_proc *new, t_vm *vm)
{
	static int			i = 1;

	if (new)
	{
		new->pos = i++;
		vm->nb_proc++;
		if (!vm->first)
		{
			vm->proc = new;
			vm->first = vm->proc;
		}
		else
		{
			new->prev = vm->proc;
			vm->proc->next = new;
			vm->proc = vm->proc->next;
		}
	}
	else
		msg_exit("No new elem\n");
}



void					first_add_proc(t_proc *new, t_vm *vm)
{
	if (new)
	{
		vm->nb_proc++;
		if (!vm->proc)
		{
			vm->proc = new;
		}
		else
		{
			vm->proc->prev = new;
			new->next = vm->proc;
			vm->proc = vm->proc->prev;
		}
	}
	else
		msg_exit("No new elem\n");
}
#if 0
Better add them as first for the init part

#endif