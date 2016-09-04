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

// void						check_arg(ac, av)
// {
// 	if ()
// }

int							main(int ac, char **av)
{
	t_vm					*vm;

	// check_arg(ac, av);
	if (ac < 2 || ac > MAX_PLAYERS + 1)
		msg_exit("Wrong number of players\n");
	vm = get_vm();
	ft_bzero(vm->memory, MEM_SIZE);
	vm->nb_champ = ac - 1;
	fill_memory(ac, av, vm);
	// print_memory(vm->memory, MEM_SIZE);
	manage_players(vm);
	// start_war(vm);

}