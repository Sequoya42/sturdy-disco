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

void					get_champ(char *s, int n, t_plr *plr)
{
	plr->n = n;
	plr->s = ft_strdup(s);
}

void					check_number(int *n, t_vm *vm)
{
	int					i;

	i = 0;
	if (*n <= 0)
		msg_exit("N must be superior to 0 [n > 0]\n");
	while (i < MAX_PLAYERS)
	{
		ft_putnbrendl(vm->plr[i].n);
		if (*n == vm->plr[i].n)
			msg_exit(N_ERR, *n, vm->plr[i].s);
		i++;
	}
}

void					check_cor(int *n, char *av, t_vm *vm)
{
	if (match(av, "*.cor"))
		get_champ(av, *n, &vm->plr[vm->nb_champ++]);
	else
		msg_exit("Bad argument: %s\n", av);
	(*n)++;
}

char					**check_arg(int ac, char **av, t_vm *vm)
{
	int					i;
	int					n;
	char				**t;

	i = 1;
	n = 1;
	vm->nb_champ = 0;
	vm->dump = -1;
	t = ft_memalloc(sizeof(*t) * (MAX_PLAYERS + 1));
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-d"))
			vm->dump = ft_atoi(av[++i]);
		else if (av[i][0] == '-' && av[i][1] == 'n')
			n = ft_atoi(av[++i]);
		else
			check_cor(&n, av[i], vm);
		i++;
		check_number(&n, vm);
	}
	ft_putnbrendl(vm->dump);
	return (t);
}
