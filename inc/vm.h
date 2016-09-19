/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:27:45 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/19 08:56:29 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include "definition.h"
# include <fcntl.h>
# include <curses.h>
# include <ncurses.h>
// #define CP				vm->proc

// typedef struct s_arg	t_arg;
typedef	struct s_plr 	t_plr;
typedef struct s_cycle	t_cycle;
typedef struct s_proc	t_proc;
typedef struct s_vm		t_vm;

struct					s_proc
{
	unsigned int		next_i;
	unsigned int		pos;
	int					num;
	unsigned int		w_st;
	unsigned int		alive;
	unsigned int		size;
	unsigned int		cycle;
	unsigned int		pc;
	unsigned int		carry : 1;
	unsigned int		reg[REG_NUMBER + 1];
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	int					set[6];
	int					arg_size[4];
	t_proc				*next;
	t_proc				*prev;
};

struct					s_plr
{
	int					n;
	char				*s;
};

struct					s_cycle
{
	unsigned int		current;
	unsigned int		check;
	unsigned int		alive;
	unsigned int		stop;
	unsigned int		total;
};

struct					s_vm
{
	int					nb_proc;
	unsigned int		visual : 1;
	unsigned int		dump;
	unsigned int		pc;
	unsigned int		nb_champ;
	unsigned int		nbr_cycle;
	t_cycle				*cycle;
	unsigned int		num_champ[MAX_PLAYERS + 1];
	unsigned char		memory[MEM_SIZE + 1];
	t_proc				*first;
	t_proc				*proc;
	t_plr				plr[MAX_PLAYERS + 1];
};

typedef void				(*t_fptr)(t_vm *vm, t_proc *p);

unsigned int				ft_swap(unsigned int val);
unsigned int				ft_endian(unsigned int val);
int							fill_memory(t_vm *vm);
int							hex_to_dec(unsigned int n);
int							format_int(int n, int size);
void						check_arg(int ac, char **av, t_vm *vm);
void						verify_last(char *s);
void						write_memory(int size, int ost, char *s, t_vm *vm);
void						start_war(t_vm *vm);
void						manage_players(t_cycle *cycle, t_vm *vm);
void						add_proc(t_proc *new, t_vm *vm);
void						get_args_size(int encode, t_proc *p);
void						put_in_set(int i, t_vm *vm, t_proc *p);
t_vm						*get_vm(void);

void						op_live(t_vm *vm , t_proc *p);
void						op_ld(t_vm *vm , t_proc *p);
void						op_st(t_vm *vm , t_proc *p);
void						op_add(t_vm *vm , t_proc *p);
void						op_sub(t_vm *vm , t_proc *p);
void						op_and(t_vm *vm , t_proc *p);
void						op_or(t_vm *vm , t_proc *p);
void						op_xor(t_vm *vm , t_proc *p);
void						op_zjmp(t_vm *vm , t_proc *p);
void						op_ldi(t_vm *vm , t_proc *p);
void						op_sti(t_vm *vm , t_proc *p);
void						op_fork(t_vm *vm , t_proc *p);
void						op_lld(t_vm *vm , t_proc *p);
void						op_lldi(t_vm *vm , t_proc *p);
void						op_lfork(t_vm *vm , t_proc *p);
void						op_aff(t_vm *vm , t_proc *p);
void						init_visual(t_vm *vm);
void						go_visual(t_vm *vm);
void						print_visual(const void *addr, size_t size, t_vm *vm);


#endif
