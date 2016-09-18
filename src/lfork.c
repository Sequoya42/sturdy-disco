/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 00:08:57 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/17 20:19:30 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void					fill_new(t_proc *n, t_proc *p)
{
	int						i;

	i = 0;
	n->pc += p->set[1];
	n->carry = p->carry;
	n->cycle = 0;
	n->num = p->num;
	while (i < PROG_NAME_LENGTH)
	{
		if (i < 16)
			n->reg[i] = p->reg[i];
		n->name[i] = p->name[i];
		i++;
	}
	n->next = NULL;
	n->prev = p;
	p->next = n;

}

void						op_lfork(t_vm *vm , t_proc *p)
{
	t_proc					*n;

	if (!(n = ft_memalloc(sizeof(t_proc))))
		msg_exit("Bad alloc of new proc [fork]\n");
	fill_new(n, p);
	(void)vm;
}
