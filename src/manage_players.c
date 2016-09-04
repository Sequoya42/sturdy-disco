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
// 00011010
 
void						manage_byte_args(int i,int op, t_vm *vm)
{
	int						encode;
	// int						size[3];

	encode = vm->memory[i];
	ft_putnbrendl(encode);
	int j = 8;

	// 011010


	int k = 0;
	// encode = 120;
	while (j >= 2)
	{
		k = (encode >> j) & 3;
		// k2 = (encode >> j) & 2;
		if ((encode >> j) & 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		// encode >>= 1;
		ft_print(KGRN "\t\t%d\n" KNRM, k);
		// ft_print(KGRN "\t\t%s\n"KNRM , ft_base(encode >> j, 2));
		j -= 2;
	}
	ft_putchar('\n');
	ft_putnbrendl(encode >> 5);
	ft_putnbrendl(encode >> 6);
	ft_putendl("end");
	ft_putnbrendl(encode);
	(void)op;
}


int							get_instructions(int ac, t_vm *vm)
{
	int						i;
	int						op;

	i = CP[ac].pc;
	op = vm->memory[i];
	CP[ac].set[0] = op;
	ft_print("op is the sane %d\n", op);
	if (GOT(op).op_mod == 1)
		manage_byte_args(i + 1, op, vm);
	// else
		// manage_args(op, vm);
	CP[ac].set[1] = op;
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