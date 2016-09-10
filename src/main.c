/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:27:37 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/03 15:27:41 by rbaum            ###   ########.fr       */
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

#endif
int							main(int ac, char **av)
{
	t_vm					*vm;
	char					**t;

	if (ac < 2)
		msg_exit("Up to %d players\n flags: -d N" \
			"to dump memory after N cycle", MAX_PLAYERS);
	vm = get_vm();
	t = check_arg(ac, av, vm);
	exit(0);
	ft_bzero(vm->memory, MEM_SIZE);
	fill_memory(vm->nb_champ, t, vm);
	start_war(vm);
	// print_memory(vm->memory, MEM_SIZE);
	// manage_players(vm);

}