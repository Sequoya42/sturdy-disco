/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 16:30:33 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/24 01:36:25 by rbaum            ###   ########.fr       */
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

void					check_dump(char **av, int *i, t_vm *vm)
{
	int					n;
	int					j;

	j = (*i) + 1;
	n = 0;
	if (av[j] && ft_string_digit(av[j]))
		n = ft_atoi(av[j]);
	else
		msg_exit("Arg must be positive integer [-d] \n");
	if (n >= 0)
		vm->dump = n;
	else
		msg_exit("Arg must be positive integer [-d] \n");
	(*i)++;
}

void					check_arg(int ac, char **av, t_vm *vm)
{
	int					i;
	int					n;
	int					nb;

	i = 1;
	n = 1;
	vm->nb_champ = 0;
	vm->dump = -1;
	nb = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-d"))
			check_dump(av, &i, vm);
		else if (!ft_strcmp(av[i], "-v"))
			vm->visual = 1;
		else if (!ft_strcmp(av[i], "-n") && av[i + 1] && ++nb)
			n = ft_atoi(av[++i]);
		else
			check_cor(&n, av[i], vm);
		i++;
		check_number(&n, vm);
	}
	if (vm->nb_champ > MAX_PLAYERS)
		msg_exit("Too many players, [max is : %d]\n", MAX_PLAYERS);
	if (vm->visual == 1 && nb == 1)
		msg_exit("-v and -n are mutually exclusive\n");
}
