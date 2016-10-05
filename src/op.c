/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2016/09/23 08:04:34 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

#if 0
02 90 00 00 01 00 02 03 70 02 00 2a 00 00
#endif
t_op		g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};


#if 0
*****
13787
turtle thunder champ fluttershy
 fight 13780 1 ressources/turtle.cor ressources/THUNDER.cor ressources/champ.cor ressources/fluttershy.cor

					CYCLE X

FIND HOW YOU MANAGE CYCLE and PROCESS_CYCLE!!

	- EXEC
	- DIE--
	- NEXT_CYCLE

******

KAPPA

1cycledif
->kill reset cycle_die-- in man player

Discrepency at 17229






----------------------
8957
come from the jymp at 03
so
see when and which

prendre op a la fin quand exec tous les bails [sti /st 2] les bails

8967

											It is now cycle 8106
P   51 | st r2 -3
ADV 5 (0x0ebc -> 0x0ec1) 03 70 02 ff fd 
P   15 | zjmp -33 OK



											Cycle [ 8106 ]
Player 51 | st [ 112 ]	2	-3	0
ADV 3	be9 -> bec	[15]
-----------------
DONE
----------------------
It is now cycle 8077
P   15 | live -16551934


t is now cycle 8082
(p15) ->   ADV 8 (0x0bdd -> 0x0be5) 03 ee 03 70 0f ff ff 01 


It is now cycle 8086
P    4 | st r2 -3

[8086]	Plyr [15]		addr: [be8]		next : [be9]		Op [UH‰åHƒì 1Àº]
[8086]	Plyr [4]		addr: [bec]		next : [bf1]		Op [st]


Tout executer puis bouger les pc??
First do those than can
Then the rest

#endif