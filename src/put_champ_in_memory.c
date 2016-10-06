/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_champ_in_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:02:58 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/30 23:10:54 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void					fill_rest(int ofst, t_proc *p)
{
	int					k;

	k = 0;
	p->pc = ofst;
	p->carry = 0;
	p->next = NULL;
	p->prev = NULL;
	p->old = -1;
	while (k < REG_SIZE + 1)
	{
		p->reg[k] = 0;
		k++;
	}
}

void					fill_champion(int ofst, char *av, t_vm *vm, t_proc *p)
{
	int					fd;
	int					i;
	char				*s;

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
	s = ft_memalloc(p->size + 1);
	lseek(fd, sizeof(int), SEEK_CUR);
	if (ft_read(fd, s, p->size) != (int)p->size)
		msg_exit("Size smaller than header says\n");
	write_memory(p->size, ofst, s, vm);
	fill_rest(ofst, p);
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
		vm->plr[i].name = ft_strdup(p->name);
		p->num = (vm->plr[i].n) * (-1);
		p->reg[1] = p->num;
		first_add_proc(p, vm);
		i++;
	}
	return (1);
}
