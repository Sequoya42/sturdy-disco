/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 02:31:42 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/25 23:29:21 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_hex_mem(unsigned char *addr, unsigned int j, t_proc *p)
{
	size_t	i;
	char	hex[] = "0123456789abcdef";
	t_proc	*t;

	i = -1;
	// int k = 0;
	while (++i < 64)
	{
		t = p;
		while (t)
		{
			if (t->pc == j)
				attron(COLOR_PAIR(-t->num));
			if (t->pc + t->size == j)
				attroff(COLOR_PAIR(-t->num));
			t = t->next;
		}
		addch(hex[(int)addr[i] / 16]);
		addch(hex[(int)addr[i] % 16]);
		j++;
		addch(' ');
	}
	// addch('\n');
}

void							print_pc(t_proc *f, t_vm *vm)
{
	int							old;
	char						hex[] = "0123456789abcdef";

	while (f)
	{
		old = f->old;
		if (old != -1)
		{
		move((old / 64) + 4 , (old % 64) * 3);
		attron(inch());
		attroff(WA_STANDOUT);
		addch(hex[(int)vm->memory[old] / 16]);
		addch(hex[(int)vm->memory[old] % 16]);
	}
		old = f->pc;
		attroff(WA_STANDOUT | inch());
		move((old / 64) + 4 , (old % 64) * 3);
		attron(WA_STANDOUT | inch());
		addch(hex[(int)vm->memory[old] / 16]);
		addch(hex[(int)vm->memory[old] % 16]);
		attroff(WA_STANDOUT);
		attroff(inch());
		f = f->next;
	}
}

// static void					print_adrr(int i)
// {
// 	unsigned int			j;
// 	char					*r;

// 	j = 0;
// 	r = ft_base(i, 16);
// 	printw("0x");
// 	while (j++ < (4 - ft_strlen(r)))
// 		addch('0');
// 	printw(r);
// 	addch('\t');
// }

void						print_sub_screen(t_vm *vm)
{
	int						i;

	i = -1;
	int x = 0; int y = 0;
	getyx(stdscr, y, x);
	printw("******************************\n");
	printw("x: %d\ty%d\n", x, y);
	printw("Cycle to die:\t%d\t    *\n", vm->cycle->stop);
	printw("Cycle total: \t%d\t    *\n", vm->cycle->total);
	printw("Nb_process:  \t%d\t    *\n", vm->nb_proc);
	printw("******************************\n");
	while (++i < MAX_PLAYERS)
		printw("\n[%s]  live(s) : %d\n", vm->plr[i].s , vm->plr[i].live);
}

void						print_visual(const void *addr, size_t size, t_vm *vm)
{
	unsigned int			i;

	i = 0;

	while (size >= 64)
	{
		// print_adrr(i);
		print_hex_mem((unsigned char*)(addr + i), i, vm->first);
		addch('\n');
		size -= 64;
		i += 64;
	}
	// print_sub_screen(vm);
	(void)vm;
}
