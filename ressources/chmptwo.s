;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    champ.s                                            :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: aelola <aelola@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2014/02/25 11:56:47 by aelola            #+#    #+#              ;
;    Updated: 2014/02/25 11:56:48 by aelola           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

.name		"lazer"
.comment	"Mundo dit beaucoup son nom pour pas l'oublier, pck c deja arriver!"

entry:
	sti		r1, %:live, %1
	sti		r1, %:mov, %1
	sti		r1, %:wall, %1
	sti		r1, %:torpille_front, %1
	sti		r1, %:write_front, %1
	and		r1, %0, r1
	ld		%100, r4
	fork	%:wall
	zjmp	%:mov

live:
	live	%1566
	fork	%:write_front
	lfork	%:mov
	zjmp	%:live

init_write:
	ld		%0, r8
	ld		%5, r15

write_front:
af:
	live	%2
	ldi		%:init_write, r8, r16
	sti		r16, %:up, r8
	add		r15, r8, r8
	sti		r16, %:up, r8
bf:
	live	%3
	xor		r8, r3, r9
	zjmp	%:init_write
cf:
	ld		%0, r9
	zjmp	%:write_front

wall:
	live	%42
	ld		%1111638594, r2
	st		r2,0
	st		r2,0
	st		r2,0
	st		r2,0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	st		r2, 0
	zjmp	%:wall

mov_init:
	ld		%4, r8
	ld		%0, r4
	ld		%1111638594, r6
	# zjmp	%:mov_init

mov:
	live	%99
	sti		r6, :up, r4
	add		r4, r8, r4
	sti		r6, :up, r4
	add		r4, r8, r4
	fork	%:mov
	zjmp	%:mov

torpille_front:
	live	%4242
	add		r4, r8, r4
	sti		r6, r4, %:up
	add		r4, r8, r4
	sti		r6, r4, %:up
	zjmp	%:torpille_front

up:
