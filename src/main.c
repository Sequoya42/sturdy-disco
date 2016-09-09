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
char						**check_arg(int ac, char **av, t_vm *vm)
{
	int						i;
	char					**t;

	i = 1;
	vm->nb_champ = 0;
	vm->dump = -1;
	t = ft_memalloc(sizeof(*t) * (MAX_PLAYERS + 1));
	while (i < ac)
	{
	if (av[i][0] == '-' && av[i][1] == 'd')
		vm->dump = ft_atoi(av[++i]);
		if (match(av[i], "*.cor"))
			t[vm->nb_champ++] = ft_strdup(av[i]);
		i++;
	}
	return (t);
}

int							main(int ac, char **av)
{
	t_vm					*vm;
	char					**t;

	if (ac < 2)
		msg_exit("Up to %d players\n flags: -d N" \
			"to dump memory after N cycle", MAX_PLAYERS);
	vm = get_vm();
	t = check_arg(ac, av, vm);
	ft_bzero(vm->memory, MEM_SIZE);
	fill_memory(vm->nb_champ, t, vm);
	start_war(vm);
	// print_memory(vm->memory, MEM_SIZE);
	// manage_players(vm);

}