/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 02:31:42 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/19 10:37:32 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_hex_mem(unsigned char *addr, unsigned int j, t_proc *p)
{
	size_t	i;
	char	hex[] = "0123456789abcdef";
	t_proc	*t;

	i = -1;
	addch('\t');
	int k = 0;
	while (++i < 64)
	{
		t = p;
		while (t)
	{
		if (t->pc == j || (t->w_st != 0 && t->w_st < MEM_SIZE && t->w_st >= (j - 3) && t->w_st <= j))
		{
			k = -t->num;
			attron(COLOR_PAIR(k));
			attron(A_STANDOUT);
		}
			t = t->next;
		}
			addch(hex[(int)addr[i] / 16]);
			addch(hex[(int)addr[i] % 16]);
			j++;
		attroff(COLOR_PAIR(k));
		attroff(A_STANDOUT);
		addch(' ');
	}
}

// static void	print_raw_mem(unsigned char *addr)
// {
// 	size_t i;

// 	i = -1;
// 	while (++i < 16)
// 	{
// 		if (addr[i] > 31 && addr[i] < 127)
// 			addch(addr[i]);
// 		else
// 			addch('.');
// 	}
// }

static void	print_adrr(int i)
{
	unsigned int	j = 0;
	char *r = ft_base(i, 16);
	printw("0x");
	while (j++ < (4 - ft_strlen(r)))
		addch('0');
	printw(r);
	addch(' ');
}

void	print_visual(const void *addr, size_t size, t_vm *vm)
{
	unsigned int			i;
	// char			s[65];
	i = 0;

	while (size >= 64)
	{
		print_adrr(i);
		print_hex_mem((unsigned char*)(addr + i), i, vm->first);
		// print_raw_mem((unsigned char*)(addr + i));
		addch('\n');
		size -= 64;
		i += 64;
	}
	(void)vm;
}
