/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 08:40:39 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/04 08:40:44 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						manage_args(int op, t_vm *vm)
{

}

void						manage_byte_args(int op, t_vm *vm)
{
	int						encode;

	encode = (vm->memory[i + 1] / 16) * 10 + (vm->memory[i + 1] % 16);
}


int							get_instructions(int ac, t_vm *vm)
{
	int						i;
	int						op;

	i = CP[ac].pc;
	op = (vm->memory[i] / 16) * 10 + (vm->memory[i] % 16);
	CP[ac].set[0] = op;
	ft_putnbrendl(op);
	if (GOT(op - 1).op_mod == 1)
		manage_byte_args(op, vm);
		op = (vm->memory[i + 1] / 16) * 10 + (vm->memory[i + 1] % 16);
	else
		manage_args(op, vm);
	CP[ac].set[1] = op;
		ft_putnbrendl(op);
	#if 0
	if (type == OPERATOR)
		return (g_op_tab[op - 1].op_mod == 0 ? 1 : 2);
	else if (type == REGISTER)
		return (T_REG);
	else if (type == DIRECT)
		return (g_op_tab[op - 1].dir_mod == 0 ? DIR_SIZE : IND_SIZE);
	else if (type == INDIRECT)
		return (IND_SIZE);
	else
		return (0);
}

	check op_table pour voir si int codage
	get params
	plug tableau pointeur sur fonction ici
	
	#endif
	return (op);
}

void						manage_players(t_vm *vm)
{
	unsigned int			i;
	unsigned int			op;

	i = -1;
	while (++i < vm->nb_champ)
	{
		op = get_instructions(i, vm);
	}
}