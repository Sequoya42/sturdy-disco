/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 08:40:39 by rbaum             #+#    #+#             */
/*   Updated: 2016/10/01 23:13:21 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int							get_instructions(t_vm *vm, t_proc *p)
{
	int						i;
	int						op;


	i = p->pc;
	op = VM(i);
	p->set[0] = op;
	if (op > 0 && op < 17)
		p->cycle = GOT(op).cycle;
	else
	{
		p->set[0] = 0;
		p->next_i = 1;
		p->cycle = 1;
 	}
	return (1);
}

void						verify_set(int i, t_vm *vm, t_proc *p);
int							verify_validity(t_proc *p, t_vm *vm)
{
	int						i;
	int						j;

	i = 0;
	(void)vm;
	put_in_set(p->pc, vm, p);
	if (GOT(p->set[0]).params == 3 && p->set[1] > 252)
		return (0);
	// if (put_in_set(p->pc, vm, p) == -1)
		// return (0);
	if (p->set[0] < 1 || p->set[0] > 16 || p->arg_size[2] == -1)
		return (0);
	j = GOT(p->set[0]).params;
	while (i < j)
	{
		p->arg_size[i] = p->arg_size[i] == 3 ? 4 : p->arg_size[i];
		if (p->arg_size[i] == 0 || !IS_IN(p->arg_size[i], p->set[0], i))
			return (0);
		i++;
	}
	return (1);
}

static t_fptr       	g_operator[CODE_LEN] =
{
    NULL,
    &op_live,
    &op_ld,
    &op_st,
    &op_add,
    &op_sub,
    &op_and,
    &op_or,
    &op_xor,
    &op_zjmp,
    &op_ldi,
    &op_sti,
    &op_fork,
    &op_lld,
    &op_lldi,
    &op_lfork,
    &op_aff
};

// #define BLA cycle->total >= 8900 && cycle->total < 9000
// #define BLA 1



void	print_address(int i)
{
	unsigned int	j = 0;
	char *r = ft_base(i, 16);
	ft_putstr("0x");
	int k = ft_strlen(r);
	if (k < 4 && k >= 0)
	while (j++ < (4 - ft_strlen(r)))
		ft_putchar('0');
	ft_putstr(r);
}

void						print_adv(t_proc *p, unsigned char *addr)
{

	char	hex[] = "0123456789abcdef";

	if (p->set[0] == 9 && p->carry == 1)
		return ;
int	i = p->pc;
int j = p->pc + p->next_i;
char str[64];
bzero(str, 64);
int k = 0;
	while (i < j)
	{
	str[k++] = (hex[(int)addr[i] / 16]);
	str[k++] = (hex[(int)addr[i] % 16]);
	str[k++] = (' ');
		i++;
	}
	printf("ADV %d (0x%04x -> 0x%04x) %s\n", p->next_i, p->pc, j, str);
}



void					print_debug(t_proc *p, t_vm *vm)
{
	int i = GOT(p->set[0]).op_mod == 0 ? 1 : 2;
if (p->set[0] == 16)
	return ;
	printf("P%5d | %s", p->pos, GOT(p->set[0]).name);
	unsigned int j = 0;
	while (j < GOT(p->set[0]).params)
	{
		if (GOT(p->set[0]).arg[j] == T_REG)
			printf(" r%d", p->set[i + j]);
		else if (p->arg_size[j] == T_REG && GOT(p->set[0]).params == 3)
			printf(" %d", p->reg[p->set[i + j]]);
		else
			printf(" %d", p->set[i + j]);
		j++;
	}

	if (p->set[0] == 11)
	{
	int		k = p->set[i + 1] + p->set[i + 2];
		printf("\n       | -> store to %d + %d = %d (with pc and mod %d)", p->set[i + 1], p->set[i + 2], k, p->pc + (k % IDX_MOD));
	}
	else if (p->set[0] == 10)
	{
	int		k = p->set[i] + p->set[i + 1];
		printf("\n       | -> load from %d + %d = %d (with pc and mod %d)", p->set[i + 0], p->set[i + 1], k, p->pc + (k % IDX_MOD));

	}
	else if (p->set[0] == 1)
	{
	int		n = p->set[1];
	int	i = 0;
	if (n)
	while (i < MAX_PLAYERS)
	{
		if (n == (vm->plr[i].n * -1))
		{
			printf("\nPlayer %d (%s) is said to be alive", vm->plr[i].n, vm->plr[i].name);
		}
		i++;
	}

	}
	else if (p->set[0] == 12 || p->set[0] == 15)
	{
		int k = p->set[0] == 15 ? p->set[1] : p->set[1] % IDX_MOD;
		printf(" (%d)", k + p->pc);
	}
	if (p->set[0] == 9 && p->carry == 1)
		printf(" OK\n");
	else if (p->set[0] == 9 && p->carry == 0)
		printf(" FAILED\n");
	else
		printf("\n");
	(void)vm;
}
void						manage_players(t_cycle *cycle, t_vm *vm)
{
	t_proc					*p;

	p = vm->first;
	(void)cycle;

	while (p)
	{	
		if ((p->set[0] == 0 || (p->cycle + 1) == GOT(p->set[0]).cycle))
		{
			get_instructions(vm, p);
			p->cycle--;	
		}
		if (p->cycle == 0)
		{
			 if (p->set[0] && verify_validity(p, vm))
			{
					if (BLA)print_debug(p, vm);
				g_operator[p->set[0]](vm, p);
			}
			if (p->next_i > 1 && BLA)
					print_adv(p, vm->memory);
			p->old = p->set[0] == 9 ? p->old : p->pc;
			p->pc += p->next_i;
			p->pc %= MEM_SIZE;
			get_instructions(vm, p);
		}
		p->cycle--;
		p = p->next;
	}
}

#if 0 

get op
if cycle
else if cycle ..
wait cycle

Imnplement pointer function tab to call each of the 16 instructions
Those who need will cann manage byte args
void func (vm, proc)
#endif