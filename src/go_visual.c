/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 02:27:55 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/30 22:19:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void					init_visual(t_vm *vm)
{
	initscr();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
	noecho();
	curs_set(FALSE);
	cbreak();
	(void)vm;
}

void					deal_with_keyboard(int *i)
{
	int					c;
	static	int			j = -1;

	c = getch();
	if (c == ' ')
		j = j == 1 ? -1 : 1;
	timeout(j);
	if (c == '+' && *i <= 1000)
		*i += 50;
	else if (c == '-' && *i > 1)
		*i = (*i > 5) ? *i - 5 : *i - 1;
	else if (c == ERR)
		refresh();
}

void					start_visual(t_vm *vm)
{
	move(0, 0);
	printw("\n\n\n\n");
	print_visual(vm->memory, MEM_SIZE, vm);
}

void					go_visual(t_vm *vm)
{
	int					sleep;
	int					sec;
	static int			i = 50;

	sec = 1000000;
	if (i < 1000)
	{
		sleep = sec / i;
		usleep(sleep);
	}
	print_pc(vm->first, vm);
	move(70, 0);
	print_sub_screen(vm);
	deal_with_keyboard(&i);
}
