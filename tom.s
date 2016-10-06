.name "tu te chute"
.comment "testeteste"

setlive:
	st r1, 7
	ld %323, r1
	ld %0, r2
	ld	%252645135, r9
	st r2, :setlive
	sti r2, %:setlive, %1
	sti r1, %:w, %1
	sti r1, %:live1, %1
	sti r1, %:loop, %1
	sti r1, %:lp, %1
	sti r1, %:wiwi, %1
	sti r1, %:l1, %1
	sti r1, %:i, %1
	sti r1, %:ii, %1
	sti r1, %:iii, %1
	sti r1, %:atc, %1
	sti r1, %:prep, %1
	ld %01, r10
	ld %0, r2

l1:
	live %12345
	fork %:atc


wall:
	st	r9, -9
	st	r9, -12
	st	r9, -23
	st	r9, -35
	st	r9, -47
	st	r9, -59
	st	r9, -71
	st	r9, -83
	st	r9, -95
	st	r9, -107
	st	r9, -119
	st	r9, -131
	st	r9, -143
	st	r9, -155
	st	r9, -167
	st	r9, -179
	st	r9, -191
	st	r9, -203
	st	r9, -215
	st	r9, -159
	st	r9, -227
	st	r9, -178
	st	r9, -239
	st	r9, -251
	st	r9, -263
	st	r9, -275
	st 	r10, -290
	st	r1, -291

w:
	live	%12345
	zjmp %:wall

atc:
	live %12345
	fork %:wiwi

loop:
	live %12345
	fork %:prep

lp:
	live %12345
	fork %:live1
	zjmp %:loop

live1:
	live	 %12345
i:
	live	 %12345
ii:
	live	 %12345
iii:
	live	 %12345
	zjmp	 %:live1

wiwi:
	live 	%12345
	ldi		%0, %:live1, r4
	sti 	r1, %:ll, %1
	ldi		%0, %:to, r5
	zjmp 	%:write

prep:
	live	%12345
	ldi		%7, %:write, r2
	ldi		%0, %:live1, r4
	sti 	r1, %:ll, %1
	ldi		%0, %:to, r5
	st 		r5, 500
	zjmp	%450

to:
	st      r4, 256

write:
	ldi		%7, %:write, r2
	st		r2, 256
	st		r2, 256
	st		r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
ll:
	live	%12345
to:
	st      r4, 256
	st      r5, 256