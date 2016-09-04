/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:27:45 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/03 15:27:57 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include <fcntl.h>

#define CP				vm->champ

typedef struct s_proc	t_proc;
typedef struct s_vm		t_vm;

struct					s_proc
{
	unsigned int		loc;
	unsigned int		size;
	unsigned int		pc;
	unsigned int		flag : 1;
	unsigned int		reg[REG_NUMBER];
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	char				*set[4];
};

struct					s_vm
{
	unsigned int		pc;
	unsigned int		nb_champ;
	unsigned int		nbr_cycle;
	unsigned int		cycle;
	unsigned int		num_champ[MAX_PLAYERS + 1];
	char				memory[MEM_SIZE];
	t_proc				champ[MAX_PLAYERS + 1];
};

int							fill_memory(int ac, char **av, t_vm *vm);
int							format_int(int n, int size);
unsigned int				ft_swap(unsigned int val);
unsigned int				ft_endian(unsigned int val);
void						verify_last(char *s);
void						write_memory(int size, int ost, char *s, t_vm *vm);
void						start_war(t_vm *vm);
void						manage_players(t_vm *vm);
t_vm						*get_vm(void);

#endif
