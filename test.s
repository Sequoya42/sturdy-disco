.name "test"
.comment "instruction test"


#ecrit un sti et un zjmp 
#etc
w2:
ld		12, r3
ld		21, r4

and		r3, r4, r2
sti		r2, %-63, %0


# w1:
# ldi		%:w2, r2, r4
# # add		r2, r4, r12
# # st		r12, 72
# sti		r4, 64, %112
# sti		r4, 64, %112
# sti		r4, 64, %112
# sti		r4, 64, %112
# sti		r4, 64, %112
# sti		r4, 64, %112


# st r1, 72
# live %-1
# ld 2, r2
# # st r1, 20
# sti r2, %50, %17
# zjmp %10


