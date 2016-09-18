/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_war.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 06:26:12 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/18 03:34:52 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						dump_memory(t_vm *vm)
{
	print_memory(vm->memory, MEM_SIZE);
	exit(0);
}


int							reset_players(t_vm *vm)
{
	t_proc					*p;
	// t_proc					*t;
	int						alive;

	p = vm->first;
	alive = 0;
	int i = 0;
	while (p)
	{

		if (p->alive == 0)
		{
			ft_print(KBLU "THIS ONE [%d] IS DEAD [Cycle is : %d]\n" KNRM , i, vm->cycle->total);
			// t = p;
			vm->nb_proc--;
			if (p->prev)
				p->prev->next = p->next;
			if (p->next)
			{
				p->next->prev = p->prev;
			// p = p->next;
			}
		}
		else
			alive++;
		p->alive = 0;
		p = p->next;
		i++;
	}
	if (alive == 0)
		return (-1);
	return (0);
}

int							loop_players(t_cycle *cycle, t_vm *vm)
{
	cycle->current = 0;
	cycle->alive = 0;
	while (cycle->current < cycle->stop)
	{
		manage_players(cycle, vm);
		if (vm->dump == cycle->total)
			dump_memory(vm);
		cycle->current++;
		cycle->total++;
	}
	reset_players(vm);	
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
	vm->cycle = &cycle;
	while (1)
	{
		if (vm->nb_proc <= 0)
			break;
		ft_print("Total : %d\t\t\tCurrent : %d\ncheck: %d\t\talive: %d\n", cycle.total, cycle.current, cycle.check, cycle.alive);
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
	 -vm->first->num, vm->first->name);
}