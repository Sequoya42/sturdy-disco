/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 02:27:55 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/21 05:02:27 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#if 0
Take care of stuff like :
-Create ncurse window to print everything
-Modify print_visual to include vm, and show all pc, and maybe color

#endif

void					init_visual(t_vm *vm)
{
	initscr();
	start_color();
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_GREEN);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
	// noecho();
	 // curs_set(FALSE);
	// cbreak();
	(void)vm;
}

void					deal_with_keyboard(int *i)
{
	int					c;

	timeout(10);
	(void)i;
	c = getch();
	if (c == ' ')
	{
		timeout(-1);
		if (getch() == ' ')
			timeout(1);
	}
	else if (c == '+' && *i < 10000)
		*i += 50;
	else if (c == '-' && *i > 1)
		*i = (*i > 5) ? *i - 5 : *i - 1;
	else if (c == ERR)
		refresh();
}
void					go_visual(t_vm *vm)
{
	int					sleep;
	int					sec;
	static int			i = 10;

	sec = 1000000;
	sleep = sec / i;
	usleep(sleep);
	move(0, 0);
	addch('\n');
	printw("Speed : %d\n", i);
	addch('\n');
	print_visual(vm->memory, MEM_SIZE, vm);
	deal_with_keyboard(&i);
	// refresh();
}