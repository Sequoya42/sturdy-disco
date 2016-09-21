/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_champ_in_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:02:58 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/21 04:31:13 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void					fill_champion(int ofst, char *av, t_vm *vm, t_proc *p)
{
	int					fd;
	int					i;

	i = 0;
	if ((fd = open(av, O_RDONLY)) <= -1)
		msg_exit("Bad file descriptor\n");
	ft_read(fd, &i, sizeof(int));
	if (ft_endian(i) != COREWAR_EXEC_MAGIC)
		msg_exit("Bad magic number\n");
	ft_read(fd, p->name, PROG_NAME_LENGTH);
	lseek(fd, sizeof(int), SEEK_CUR);
	ft_read(fd, &i, sizeof(int));
	p->size = ft_endian(i);
	if (p->size > CHAMP_MAX_SIZE)
		msg_exit("%d : Too big a champion !\nMax size is %d\n",
		 p->size, CHAMP_MAX_SIZE);
	ft_read(fd, p->comment, COMMENT_LENGTH);
	char *s = ft_memalloc(p->size + 1);
		lseek(fd, sizeof(int), SEEK_CUR);
	ft_read(fd, s, p->size);
	write_memory(p->size, ofst, s, vm);
	p->pc = ofst;
	p->carry = 0;
	p->next = NULL;
	p->prev = NULL;
	// ft_print("size: %d\nname:\t%s\ncomment:\t%s\n", p->size, p->name, p->comment);
	// exit(0);
}

int						fill_memory(t_vm *vm)
{
	unsigned int		dist;
	int					i;
	int					ac;
	t_proc				*p;

	ac = vm->nb_champ;
	dist = MEM_SIZE / (ac);
	i = 0;
  	while (i < ac)
	{
		if (!(p = ft_memalloc(sizeof(t_proc))))
			msg_exit("Bad alloc of processus\n");
		fill_champion((i * dist), vm->plr[i].s, vm, p);
		p->num = (vm->plr[i].n) * (-1);
		p->reg[1] = p->num;
		p->w_st = -10;
		add_proc(p, vm);
		i++;
	}
	// vm->first = vm->proc;
	return (1);
}
