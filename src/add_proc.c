/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 03:49:22 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/29 00:39:55 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// Implement prev
void					add_proc(t_proc *new, t_vm *vm)
{
	// static int			i = 1;

	if (new)
	{
		// new->pos = i++;
		vm->nb_proc++;
		// ft_putendl("\t\t\t\t\tELSE");
		vm->proc->next = new;
		new->prev = vm->proc;
		vm->proc = vm->proc->next;
	}
	else
		msg_exit("No new elem\n");
}



void					first_add_proc(t_proc *new, t_vm *vm)
{
	if (new)
	{
		vm->nb_proc++;
		if (!vm->first)
		{
			vm->first = new;
			vm->proc = vm->first;
		}
		else
		{
			vm->first->prev = new;
			new->next = vm->first;
			vm->first = vm->first->prev;
		}
	}
	else
		msg_exit("No new elem\n");
}
#if 0
Better add them as first for the init part

#endif