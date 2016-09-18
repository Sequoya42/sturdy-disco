/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:07:11 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/18 04:05:02 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_st(t_vm *vm , t_proc *p)
{
	int						n;
	int						r;
	char					*s;

	n = 0;
	r = (p->arg_size[0] == REG_CODE) ? p->reg[p->set[2]] : p->set[2];
	r = -1;
	if (p->arg_size[1] == REG_CODE)
		p->reg[p->set[3]] = r;
	else
	{
		n = p->pc + (p->set[3] % IDX_MOD);
		ft_print("ST SUPPOSE TO WRITE SOMETHING [r is %d]  at %d !\n", r, n);
		VM(n) = (unsigned char )&r;
		ft_putchar(VM(n));
		ft_putchar('\n');
		exit(0);
	}
}


#if 0

You suppose to write 4 char yo

so kind of reverse this:

	r |= (VM(*i + 1) << 24);
	r |= (VM(*i + 2) << 16);
	r |= (VM(*i + 3) << 8);
	r |= (VM(*i + 4));

From n, and then... blablabla

or more like


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
			// ft_print("OP: %d\t\targ size: %d\n", p->set[0], p->arg_size[i]);
		j -= 2;
		i++;
	}
}


#endif