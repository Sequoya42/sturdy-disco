/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:27:37 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/19 08:38:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
//-d could be anywhere

#if 0
Finished check_arg, assign right number with -n
put them [process] in char**, for the name, and an int 
so structure...
OR | join name with number.. so just one tab

p->number = n != (i * -1) ? n : ()
CHECK THE TODO
#endif

void						test_shit(t_vm *vm)
{
(void)vm;
	t_proc *p = vm->first;
	while (p)
	{
		ft_print("p->num = %d\n", -(p->num));
		p = p->next;
	}
	exit(0);
}

int							main(int ac, char **av)
{
	t_vm					*vm;
	
	if (ac < 2)
		msg_exit("Up to %d players\n flags: -d N" \
			"\tto dump memory after N cycle\n", MAX_PLAYERS);
	vm = get_vm();
	vm->nb_proc = 0;
	check_arg(ac, av, vm);
	ft_print("numbet player : %d\n", vm->nb_champ);
	ft_bzero(vm->memory, MEM_SIZE);
	fill_memory(vm);
	// test_shit(vm);
	if (vm->visual == 1)
	{
		init_visual(vm);
	}
	start_war(vm);
	return (0);
}