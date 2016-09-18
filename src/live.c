/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 03:10:10 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/18 03:34:38 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						op_live(t_vm *vm, t_proc *p)
{
	// int						n;

	if (p->set[1] == p->num)
	{
		ft_print("\t\t\t\t%s is alive !\n", p->name);
		p->alive++;
	}
	vm->cycle->alive++;
}

#if 0

#endif