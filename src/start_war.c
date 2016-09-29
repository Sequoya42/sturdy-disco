/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_war.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 06:26:12 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/29 15:54:43 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						dump_memory(t_vm *vm)
{
	print_memory(vm->memory, MEM_SIZE);
	exit(0);
}

int							remove_player(t_vm *vm, t_proc *p)
{
	vm->nb_proc--;
	if (p == vm->proc)
		vm->proc = vm->proc->prev;
	if (p == vm->first && vm->first->next)
		vm->first = vm->first->next;
	else if (p == vm->first && !vm->first->next)
		return (-1);


	if (p->prev)
		p->prev->next = p->next;
	else
		p->prev = NULL;
	if (p->next)
		p->next->prev = p->prev;
	else
		p->next = NULL;
	if (vm->visual == 1)
		print_coord(p->pc, vm);
	return (0);
}

int							reset_players(t_vm *vm)
{
	t_proc					*p;

	p = vm->first;
	int i = 0;
	while (p)
	{
		if (p->alive == 0)
		{
			if (remove_player(vm, p) == -1)
				return (-1);
		}
		p->alive = 0;
		p = p->next;
		i++;
	}
	return (0);
}

int							loop_players(t_cycle *cycle, t_vm *vm)
{
	int						i;

	i = -1;
	cycle->current = 0;
	cycle->alive = 0;
	while (cycle->current < cycle->stop)
	{
		manage_players(cycle, vm);
		if (vm->dump == cycle->total)
			dump_memory(vm);
		if (vm->visual == 1)
			go_visual(vm);
		cycle->current++;
		cycle->total++;
	}
	while (++i < MAX_PLAYERS)
		vm->plr[i].live = 0;
	if (reset_players(vm) == -1)
	{
		ft_print("Trouble at cycle : %d\n", cycle->total);
		return (-1);
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
	vm->cycle = &cycle;
	if (vm->visual == 1)
		start_visual(vm);
	while (1)
	{
		if (loop_players(&cycle, vm) == -1)
			break;
		if (cycle.alive >= NBR_LIVE || cycle.check == MAX_CHECKS)
		{
			cycle.stop -= CYCLE_DELTA;
			cycle.check = 0; // Maybe cycle check 0 only if max check
		}
		if (cycle.alive == 0 || (int)cycle.stop <= 0)
			break;
	}
	ft_print("cycle: %d\tContestant %d, \"%s\", has won !\n",cycle.total,
			 -vm->first->num, vm->first->name);
}