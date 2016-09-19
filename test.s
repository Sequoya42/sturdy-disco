.name "test"
.comment "instruction test"


#ecrit un sti et un zjmp 
#etc
w1:
add r16, r16, r16
zjmp %0
zjmp %14
ld %80, r2

# st r1, 72
# live %-1
# ld 2, r2
# # st r1, 20
# sti r2, %50, %17
# zjmp %10


