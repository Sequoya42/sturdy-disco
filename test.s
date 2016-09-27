.name "test"
.comment "instruction test"



ld %251658255, r2
st r1, -1
st r2, 314
st r16, -4
st r16, -300
st r2, -301
st r2, -302

#ecrit un sti et un zjmp 
#etc
# w2:
# ld		3, r3

# sti		r3, %63, %12
# sti		r4, %63, %12


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


