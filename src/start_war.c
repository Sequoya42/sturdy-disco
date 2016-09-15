/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_war.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 06:26:12 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/04 06:26:17 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						dump_memory(t_vm *vm)
{
	print_memory(vm->memory, MEM_SIZE);
	exit(0);
}

int							loop_players(t_cycle *cycle, t_vm *vm)
{
	cycle->current = 0;
	while (cycle->current < cycle->stop)
	{
		manage_players(cycle, vm);
		if (vm->dump == cycle->total)
			dump_memory(vm);
		cycle->current++;
		cycle->total++;
	}
	cycle->check++;
	return (0);
}

void						start_war(t_vm *vm)
{
	t_cycle					cycle;

	cycle.total = 0;
	cycle.stop = CYCLE_TO_DIE;
	cycle.check = 0;
	cycle.alive = 0;
	while (1)
	{
		if (loop_players(&cycle, vm) == -1)
			break;
		if (cycle.alive >= NBR_LIVE || cycle.check == MAX_CHECKS)
		{
			cycle.stop -= CYCLE_DELTA;
			cycle.check = 0;
		}
		if (cycle.alive == 0 || (int)cycle.stop <= 0)
			break;
	}
	ft_print("Contestant %d, \"%s\", has won !\n",
	 vm->first->reg[0], vm->first->name);
}