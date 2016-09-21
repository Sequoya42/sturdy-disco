/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 02:31:42 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/21 05:13:11 by rbaum            ###   ########.fr       */
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
			if (t->pc == j || COLORN(t->w_st, (int)j))
			{
				k = -t->num;
				attron(COLOR_PAIR(k));
				attron(A_STANDOUT);
			}
			t = t->next;
		}
		// if ((int)addr[i] % 16 == 0 && (int)addr[i] / 16 == 0)
			// attron(COLOR_PAIR(5));
		addch(hex[(int)addr[i] / 16]);
		addch(hex[(int)addr[i] % 16]);
		j++;
		attron(COLOR_PAIR(8));
		attroff(A_STANDOUT);
		addch(' ');
	}
	// addch('\n');
}

static void					print_adrr(int i)
{
	unsigned int			j;
	char					*r;

	j = 0;
	r = ft_base(i, 16);
	printw("0x");
	while (j++ < (4 - ft_strlen(r)))
		addch('0');
	printw(r);
	addch('\t');
}

void						print_sub_screen(t_vm *vm)
{
	int						i;

	i = -1;
	printw("******************************\n");
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
		print_adrr(i);
		print_hex_mem((unsigned char*)(addr + i), i, vm->first);
		addch('\n');
		size -= 64;
		i += 64;
	}
	print_sub_screen(vm);
	(void)vm;
}
