/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 03:49:22 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/10 03:49:27 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// Implement prev
void					add_proc(t_proc *new, t_vm *vm)
{
	if (new)
	{
		if (!vm->first)
		{
			vm->proc = new;
			vm->first = vm->proc;
		}
		else
		{
			vm->proc->next = new;
			vm->proc = vm->proc->next;
		}
	}
	else
		msg_exit("No new elem\n");
}
