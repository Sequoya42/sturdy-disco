/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 02:31:42 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/20 00:52:10 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_hex_mem(unsigned char *addr, unsigned int j, t_proc *p)
{
	size_t	i;
	char	hex[] = "0123456789abcdef";
	t_proc	*t;

	i = -1;
	int k = 0;
	while (++i < 64)
	{
		t = p;
		while (t)
		{
			if (t->pc == j || (t->w_st == j && j != 0))
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

static void	print_adrr(int i)
{
	unsigned int	j = 0;
	char *r = ft_base(i, 16);
	printw("0x");
	while (j++ < (4 - ft_strlen(r)))
		addch('0');
	printw(r);
	addch('\t');
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
		t_proc *t;
		t = vm->first;
		while (t)
		{
			printw("\n%d is alive ! %d\n", t->num, t->alive);
			t=t->next;
		}
	(void)vm;
}
