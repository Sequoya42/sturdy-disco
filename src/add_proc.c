/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 03:49:22 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/29 23:03:09 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void					first_add_proc(t_proc *new, t_vm *vm)
{
	static int			i = 1;

	if (new)
	{
		new->pos = i++;
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
