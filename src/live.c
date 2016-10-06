/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 03:10:10 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/27 23:34:48 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_live(t_vm *vm, t_proc *p)
{
	int						n;
	int						i;

	n = p->set[1];
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (n == (vm->plr[i].n * -1))
		{
			vm->plr[i].live++;
			vm->plr[i].last = vm->cycle->total;
		}
		i++;
	}
	p->alive++;
	vm->cycle->alive++;
}
