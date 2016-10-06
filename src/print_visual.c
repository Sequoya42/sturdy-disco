/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 02:31:42 by rbaum             #+#    #+#             */
/*   Updated: 2016/10/01 18:13:18 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						print_mem(unsigned char *addr, int j, t_proc *p)
{
	size_t					i;
	static char				hex[] = "0123456789abcdef";
	t_proc					*t;

	i = -1;
	init_color(COLOR_MAGENTA, 254, 254, 254);
	init_pair(17, COLOR_MAGENTA, COLOR_BLACK);
	while (++i < 64)
	{
		t = p;
		while (t)
		{
			if (t->pc == (unsigned int)j)
				attron(COLOR_PAIR(-t->num));
			if (t->pc + t->size == (unsigned int)j)
				attron(COLOR_PAIR(17));
			t = t->next;
		}
		addch(hex[(int)addr[i] / 16]);
		addch(hex[(int)addr[i] % 16]);
		j++;
		addch(' ');
	}
}

void						print_coord(int old, t_vm *vm)
{
	static char				hex[] = "0123456789abcdef";

	move(Y(old), X(old));
	attron(inch() & A_COLOR);
	attroff(A_STANDOUT);
	addch(hex[VM(old) / 16]);
	addch(hex[VM(old) % 16]);
	attroff(inch() & A_COLOR);
}

void						print_pc(t_proc *f, t_vm *vm)
{
	int						old;
	static char				hex[] = "0123456789abcdef";

	while (f)
	{
		old = f->old;
		if (old != -1)
			print_coord(old, vm);
		old = f->pc;
		move(Y(old), X(old));
		attron((inch() & A_COLOR) | A_STANDOUT);
		addch(hex[VM(old) / 16]);
		addch(hex[VM(old) % 16]);
		attroff((inch() & A_COLOR) | A_STANDOUT);
		f = f->next;
	}
}

void						print_sub_screen(t_vm *vm)
{
	int						i;
	int						j;

	i = -1;
	j = 4;
	mvprintw(j++, 222, "******************************\n");
	mvprintw(j++, 222, "* Cycle to die:\t%d\t    *", vm->cycle->stop);
	mvprintw(j++, 222, "* Cycle total: \t%d\t    *", vm->cycle->total);
	mvprintw(j++, 222, "* Nb_process:  \t%d\t    *", vm->nb_proc);
	mvprintw(j++, 222, "******************************\n");
	j++;
	while (++i < vm->nb_champ)
	{
		attron(COLOR_PAIR(i + 1));
		mvprintw(j++, 222, "[%s] last : %d", vm->plr[i].s, vm->plr[i].last);
		attroff(COLOR_PAIR(i + 1));
		mvprintw(j++, 222, "Nb live(s) : %d", vm->plr[i].live);
		j++;
	}
}

void						print_visual(void *addr, size_t size, t_vm *vm)
{
	unsigned int			i;
	unsigned int			k;

	i = 0;
	k = 0;
	while (size >= 64)
	{
		printw("*   ", ++k);
		print_mem((unsigned char*)(addr + i), i, vm->first);
		addch('\n');
		size -= 64;
		i += 64;
	}
	(void)vm;
}
