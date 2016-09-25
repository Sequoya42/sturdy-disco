/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 03:13:46 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/25 16:55:01 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITION_H
# define DEFINITION_H

typedef enum e_code				t_opcode;

# define DEBUG					0

# define NC_SIZE				192
# define BREAK_CHAR				"," " " "\t" "\0" "\r" "\n"
# define NUM_CHAR				"-1234567890"
# define GOT(x)					g_op_tab[x - 1]
# define M(x)					(x % MEM_SIZE)
# define COLORN(x, y)			( M(x) == y || M(x + 1) == y\
								|| M(x + 2) == y || M(x + 3) == y)

# define INT_MAX				2147483648l

#define V_REG(x)				(x < 0 || x > REG_NUMBER) ? 0 : x

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
# define N_ERR					"Number [ %d ] already used by previous champ %s\n"

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
