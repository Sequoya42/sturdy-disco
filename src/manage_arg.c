/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 02:44:43 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/19 14:52:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						get_args_size(int encode, t_proc *p)
{
	int						i;
	int						j;

	j = 8;
	i = 0;
	encode <<= 2;
	while (j >= 4)
	{
		p->arg_size[i] = (encode >> j) & 3;
		j -= 2;
		i++;
	}
}

int							manage_ind(int *i, t_vm *vm)
{
	int					r;

	r = 0;
	r |= (VM(*i + 1) << 8);
	r |= (VM(*i + 2));
	if (r > 65025)
	{
		r &= 0xFF;
		r = ft_endian(r) * -1;
		r = format_int(r, T_IND) * -1;
	}
	*i += 2;
	return (r);
}

int							manage_dir(int *i, t_vm *vm, t_proc *p)
{
	int						nb_byte;
	int						r;

	r = 0;
	nb_byte = ISDIR ? 2 : 4;
	if (nb_byte == 2)
		return (manage_ind(i, vm));
	r |= (VM(*i + 1) << 24);
	r |= (VM(*i + 2) << 16);
	r |= (VM(*i + 3) << 8);
	r |= (VM(*i + 4));
	// ft_putendl("******************");
	// ft_putnbrn(VM(*i + 1));
	// 	ft_putnbrn(VM(*i + 3));
	// 		ft_putnbrn(VM(*i + 3));
	// 			ft_putnbrn(VM(*i + 4));
	// 				ft_putendl("\n******************");
	*i += 4;
	return (r);
}

void						put_in_set(int i, t_vm *vm, t_proc *p)
{
	unsigned int						j;
	unsigned int						k;

	j = 0;
	p->next_i = 1;
	k = 1;
	if (GOT(p->set[0]).op_mod == 1 && (p->next_i++) && (k++))
		get_args_size(VM(++i), p);
	else
		p->arg_size[0] = GOT(p->set[0]).arg[0];
	p->set[1] = VM(i);
	while (j < GOT(p->set[0]).params)
	{
		if (p->arg_size[j] == REG_CODE && (p->next_i++))
			p->set[k] = VM(++i);
		else if (p->arg_size[j] == DIR_CODE && (p->next_i += ISDIR ? 2 : 4))
			p->set[k] = manage_dir(&i, vm, p);
		else if (p->arg_size[j] == IND_CODE && (p->next_i += 2))
			p->set[k] = manage_ind(&i, vm);
		j++;
		k++;
	}
	// j = 0;


	ft_print("op: %d\tnext i: %d\tpc:\t%d\n", p->set[0], p->next_i, p->pc);
	while (j < 5)
	{
		ft_print("set[%d]:\t%d\n", j, p->set[j]);
		j++;
	}

	
}



