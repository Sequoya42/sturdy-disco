/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 03:13:46 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/27 17:19:14 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITION_H
# define DEFINITION_H

typedef enum e_code				t_opcode;

# define BLA 0
# define DEBUG					0
# define REDO					(p->cycle + 1) == GOT(p->set[0]).cycle

# define Y(x)					(x / 64) + 4
# define X(x)					((x % 64) *3) + 4

# define NC_SIZE				192
# define BREAK_CHAR				"," " " "\t" "\0" "\r" "\n"
# define NUM_CHAR				"-1234567890"
# define GOT(x)					g_op_tab[x - 1]
# define M(x)					(x % MEM_SIZE)

# define V_REG(x)				(x < 0 || x > REG_NUMBER) ? 0 : x

# define ISDIR					(GOT(p->set[0]).dir_mod == 1)

# define VM(x)					(vm->memory[(x) % MEM_SIZE])

# define LEFT_SHIFT				0XFF00FF00
# define RIGHT_SHIFT			0xFF00FF
# define TKN_HEAD				token_head(NULL)
# define LBL_HEAD				label_head(NULL)
# define IS_IN(x, y, z)			((x == (int)(x & GOT(y).arg[z])) ? 1 : 0)

# define WRITE_INT(x)			ft_endian(x)
# define SWAP(x)				((x >> 8) | (x << 8))
# define ARG_ONE				t->next
# define ARG_TWO				t->next->next
# define ARG_THREE				t->next->next->next
# define N_ERR					"Number [ %d ] already used by %s\n"

enum							e_type
{
	REGISTER = REG_CODE,
	DIRECT = DIR_CODE,
	INDIRECT = IND_CODE,
	LABEL,
	OPERATOR,
	TYPE_LEN
};

enum							e_code
{
	LIVE = 1,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF,
	CODE_LEN
};

#endif
