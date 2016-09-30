/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 02:44:43 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/30 20:29:49 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						get_args_size(int encode, t_proc *p)
{
	p->arg_size[0] = (encode >> 6) & 3;
	p->arg_size[1] = (encode >> 4) & 3;
	p->arg_size[2] = (encode >> 2) & 3;
}

int							manage_ind(int *i, t_vm *vm, t_proc *p)
{
	int					r;

	r = 0;
	if (DEBUG == 1)
		ft_putendl("INDIRECT");
	r |= (VM(*i + 1) << 8);
	r |= (VM(*i + 2));
	if (r > 32768) // = 255 * 255
		r = -(65536 - r);
 	*i += 2;
 	(void)p;
	return (r);
}

int							manage_dir(int *i, t_vm *vm, t_proc *p)
{
	int						nb_byte;
	int						r;

	r = 0;
	nb_byte = ISDIR ? 2 : 4;
	if (nb_byte == 2)
		return (manage_ind(i, vm, p));
	if (DEBUG == 1)
		ft_putendl("DIRECT");
	r |= (VM(*i + 1) << 24);
	r |= (VM(*i + 2) << 16);
	r |= (VM(*i + 3) << 8);
	r |= (VM(*i + 4));
	*i += 4;
	return (r);
}

void						verify_set(int i, t_vm *vm, t_proc *p)
{
	int						k;
	unsigned	int						j;


	k = GOT(p->set[0]).op_mod == 0 ? 1 : 2;
	i = k == 1 ? i : i + 1;
	j = 0;
	while (j < GOT(p->set[0]).params)
	{
		// ft_print("I : %d\n", i);
		if (p->arg_size[j] == REG_CODE && i++)
		{
			if ((p->set[k] = V_REG(VM(i))) == 0)
				p->arg_size[j] = 0;
		}
		else if (p->arg_size[j] == DIR_CODE)
			p->set[k] = manage_dir(&i, vm, p);
		else if (p->arg_size[j] == IND_CODE)
			p->set[k] = manage_ind(&i, vm, p);
		j++;
		k++;
	}
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
		if (p->arg_size[j] == REG_CODE && (p->next_i++) && ++i)
		{
			if ((p->set[k] = V_REG(VM(i))) == 0)
				p->arg_size[j] = 0;
		}
		else if (p->arg_size[j] == DIR_CODE && (p->next_i += ISDIR ? 2 : 4))
			p->set[k] = manage_dir(&i, vm, p);
		else if (p->arg_size[j] == IND_CODE && (p->next_i += 2))
			p->set[k] = manage_ind(&i, vm, p);
		j++;
		k++;
	}
	if (DEBUG == 1)
	{
		j = 0;
		ft_print("CYCLE : %d\n", vm->cycle->total);
		ft_print(KGRN "op: [%s] %d\tnext i: %d\tpc:\t%d\n" KNRM, GOT(p->set[0]).name, p->set[0], p->next_i, p->pc);
		while (j < 5)
		{
			ft_print("set[%d]:\t%d\n", j, p->set[j]);
			j++;
		}
	}	
}



