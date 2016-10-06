/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:27:37 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/29 21:10:58 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						introducing(int n, t_proc *p)
{
	int						i;

	i = -1;
	ft_putendl("Introducing contestants...");
	while (++i < n)
	{
		ft_print("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			-p->num, p->size, p->name, p->comment);
		p = p->prev;
	}
}

void						print_winner(t_vm *vm)
{
	unsigned int			j;
	int						i;
	int						k;

	i = -1;
	j = 0;
	k = 0;
	while (++i < vm->nb_champ)
	{
		if (vm->plr[i].last >= j)
		{
			j = vm->plr[i].last;
			k = i;
		}
	}
	ft_print("Contestant %d, \"%s\", has won !\n",
		vm->plr[k].n, vm->plr[k].name);
	if (vm->visual == 1)
	{
		move(20, 250);
		timeout(-1);
		printw("FINISHED !\tPress any key to escape!");
		getch();
		endwin();
	}
}

int							main(int ac, char **av)
{
	t_vm					*vm;

	if (ac < 2)
		msg_exit("Up to %d players\n flags: -d N" \
			"\tto dump memory after N cycle\n", MAX_PLAYERS);
	vm = get_vm();
	vm->nb_champ = 0;
	vm->nb_proc = 0;
	vm->visual = 0;
	check_arg(ac, av, vm);
	ft_bzero(vm->memory, MEM_SIZE);
	fill_memory(vm);
	if (vm->visual == 1)
		init_visual(vm);
	introducing(vm->nb_champ, vm->proc);
	start_war(vm);
	print_winner(vm);
	return (0);
}
