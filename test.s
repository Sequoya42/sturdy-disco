.name "test"
.comment "instruction test"


#ecrit un sti et un zjmp 
#etc
w2:
ld		%8, r2


w1:
ldi		%:w2, r2, r4
sti		r4, 400, r2
ldi		%:w2, r2, r4
ld		%0, r3
zjmp 	%-14
st		r2, 42

# st r1, 72
# live %-1
# ld 2, r2
# # st r1, 20
# sti r2, %50, %17
# zjmp %10


