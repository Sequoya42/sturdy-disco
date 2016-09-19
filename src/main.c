/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:27:37 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/20 00:58:50 by rbaum            ###   ########.fr       */
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
int	n = -210;
int	r = ft_endian(n);
int	k = ft_endian(r);
	ft_print("n : %d\tr: %d\t k:%d\n", n , r, k);
(void)vm;
// 	t_proc *p = vm->first;
// 	while (p)
// 	{
// 		ft_print("p->num = %d\n", -(p->num));
// 		p = p->next;
// 	}
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
	vm->visual = 0;
	check_arg(ac, av, vm);
	ft_bzero(vm->memory, MEM_SIZE);
	fill_memory(vm);
	// test_shit(vm);
	if (vm->visual == 1)
		init_visual(vm);
	start_war(vm);
	printw("FINISHED !\n, press any key to escape!");
	timeout(-1);
	getch();
	endwin();
	return (0);
}