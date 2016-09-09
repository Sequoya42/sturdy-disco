/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 16:30:33 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/09 16:30:37 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void					assign_player_number(int n, int *i, char **av, t_vm *vm)
{
	t_proc				*p;

	if (!(p = ft_memalloc(sizeof(t_proc))))
			msg_exit("Bad alloc of processus\n");
		fill_champion((i * dist), av[i], vm, p);
		p->reg[0] = -1, -2 etc or if -n do otherwise blabla
		add_proc(p, vm);	
}

char					**check_arg(int ac, char **av, t_vm *vm)
{
	int					i;
	char				**t;

	i = 1;
	vm->nb_champ = 0;
	vm->dump = -1;
	t = ft_memalloc(sizeof(*t) * (MAX_PLAYERS + 1));
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == 'd')
			vm->dump = ft_atoi(av[++i]);
		else if (av[i][0] == '-' && av[i][1] == 'n')
		{
			ft_atoi(av[i + 1]);
			assign_player_number(vm);
		}
		else if (match(av[i], "*.cor"))
			t[vm->nb_champ++] = ft_strdup(av[i]);
		else
			msg_exit("Bad argument");
		i++;
	}
	return (t);
}
