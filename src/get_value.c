/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 07:57:53 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/29 20:59:54 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						write_value(int r, unsigned int n, t_vm *vm)
{
	VM(n) = (r >> 24);
	VM(n + 1) = (r >> 16);
	VM(n + 2) = (r >> 8);
	VM(n + 3) = (r);
}

int							get_value(t_proc *p, int i, int j, t_vm *vm)
{
	int						r;
	int						n;

	r = 0;
	if (p->arg_size[i] == REG_CODE)
		return (p->reg[p->set[j]]);
	else if (p->arg_size[i] == 4)
	{
		n = p->pc + p->set[j];
		r |= (VM(n + 0) << 24);
		r |= (VM(n + 1) << 16);
		r |= (VM(n + 2) << 8);
		r |= (VM(n + 3));
		return (r);
	}
	else
		return (p->set[j]);
}
