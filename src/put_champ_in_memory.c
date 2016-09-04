/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_champ_in_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:02:58 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/03 16:03:02 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void						fill_champion(int ofst, int ac, char *av, t_vm *vm)
{
	int						fd;
	int						i;

	i = 0;
	if ((fd = open(av, O_RDONLY)) <= -1)
		msg_exit("Bad file descriptor\n");
	ft_read(fd, &i, sizeof(int));
	if (ft_endian(i) != COREWAR_EXEC_MAGIC)
		msg_exit("Bad magic number\n");
	ft_read(fd, vm->champ[ac].name, PROG_NAME_LENGTH);
	lseek(fd, sizeof(int), SEEK_CUR);
	ft_read(fd, &i, sizeof(int));
	vm->champ[ac].size = ft_endian(i);
	if (CP[ac].size > CHAMP_MAX_SIZE)
		msg_exit("%d : Too big a champion !\nMax size is %d\n",
		 CP[ac].size, CHAMP_MAX_SIZE);
	ft_read(fd, vm->champ[ac].comment, COMMENT_LENGTH);
	char *s = ft_memalloc(CP[ac].size + 1);
		lseek(fd, sizeof(int), SEEK_CUR);
	ft_read(fd, s, CP[ac].size);
	write_memory(CP[ac].size, ofst, s, vm);
	CP[ac].pc = ofst;
	CP[ac].loc = ofst;
	// ft_print("size: %d\nname:\t%s\ncomment:\t%s\n", CP[ac].size, CP[ac].name, CP[ac].comment);
}

int							fill_memory(int ac, char **av, t_vm *vm)
{
	unsigned int			dist;
	unsigned int			i;

	dist = MEM_SIZE / (ac - 1);
	i = 0;
	while (--ac)
	{
		fill_champion((i * dist), ac, av[ac], vm);
		i++;
	}
	return (1);
}
