/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 02:44:43 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/14 02:44:47 by rbaum            ###   ########.fr       */
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
		ft_print("OP: %d\t\targ size: %d\n", p->set[0], p->arg_size[i]);
		j -= 2;
		i++;
	}
}

int							manage_ind(int i, t_vm *vm)
{
	int					r;

	r = 0;
	r |= (vm->memory[i + 1] << 8);
	r |= (vm->memory[i + 2]);
	// ft_print("i + 1: %d \t\t i + 2 : %d\n", vm->memory[i + 1], vm->memory[i + 2]);
	// ft_print("%d\tIND, value of r : %d\n", i, r);
	return (r);
}

int							manage_dir(int i, t_vm *vm, t_proc *p)
{
	int						nb_byte;
	int						r;

	r = 0;
	nb_byte = ISDIR ? 2 : 4;
	if (nb_byte == 2)
		return (manage_ind(i, vm));
	r |= (vm->memory[i + 1] << 24);
	r |= (vm->memory[i + 2] << 16);
	r |= (vm->memory[i + 3] << 8);
	r |= (vm->memory[i + 4]);
	// ft_print(KGRN "%d\tDIR, value of r: %d\n" KNRM, i, r);
	return (r);
}

void						put_in_set(int i, t_vm *vm, t_proc *p)
{
	unsigned int						j;

	j = 0;
	p->next_i = 1;
	if (GOT(p->set[0]).op_mod == 1 && (p->next_i++))
		get_args_size(vm->memory[++i], p);
	else
		p->arg_size[0] = GOT(p->set[0]).arg[0];
	p->set[1] = vm->memory[i];
	while (j < GOT(p->set[0]).params)
	{
		if (p->arg_size[j] == REG_CODE && (p->next_i += 1))
			p->set[j + 2] = vm->memory[i++];
		else if (p->arg_size[j] == DIR_CODE && (p->next_i += ISDIR ? 2 : 4))
			p->set[j + 2] = manage_dir(i, vm, p);
		else if (p->arg_size[j] == IND_CODE && (p->next_i += 2))
			p->set[j + 2] = manage_ind(i, vm);
		j++;
	}
	p->pc += p->next_i;
	ft_print("op: %d\tnext i: %d\tpc:\t%d\n", p->set[0], p->next_i, p->pc);
	// ft_print("PARAMS: %d\n", GOT(p->set[0]).params);
	// p->pc += p->arg_size[0] + p->arg_size[1] + p->arg_size[2];
}



