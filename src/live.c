/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 03:10:10 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/20 00:36:56 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_live(t_vm *vm, t_proc *p)
{
	// int						n;
	// ft_print("PC IN LIVE %d\n", p->pc);
	if (p->set[1] == p->num)
	{
		// ft_print("\t\t\t\t%s is alive !\n", p->name);
		p->alive++;
	}
	// vm->cycle->alive++;
	(void)vm;
}

#if 0

#endif