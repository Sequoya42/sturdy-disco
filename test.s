.name "test"
.comment "instruction test"


sti r1, %32767, %0
sti r1, %64516, %0
sti r1, %64517, %0
sti r1, %64770, %0

#####################################################

# fork %250
# assaut1:
# live %0
# ld %190055943, r10 # sti r6, r7
# ld %84476405, r11 # r5 jump 01F5 (501)
# fork %:second
# ld %190055172, r3 #0x0B540304
# ld %190055172, r6 #0x0B540304
# ld %507, r7
# ld %24, r4
# ld %0, r5
# zjmp %:jump

# second:
# live %0
# ld %84475923, r3 #0x0509001b
# ld %84475923, r6
# ld %511, r7
# ld %28, r4
# ld %0, r5
# zjmp %:jump

# jump:
# live %0
# st r10, 511
# st r11, 510
# zjmp %501
#######################################################
# fork %:ledroi
# ld %190055943, r10 # sti r6, r7
# ld %84476405, r11 # r5 jump 01F5 (501)
# ld %150994956, r3 #0x0900000c
# ld %150994956, r6 #0x0900000c
# sti r10, r11, r13
# # ld %251658255, r2
# # st r1, -1
# # st r2, 314
# # st r16, -4
# # st r16, -300
# # st r2, -301
# # st r2, -302

# # #ecrit un sti et un zjmp 
# # #etc
# # w2:
# # ld		3, r3

# # sti		r3, %63, %12
# # sti		r4, %63, %12


# # w1:
# # ldi		%:w2, r2, r4
# # # add		r2, r4, r12
# # # st		r12, 72
# # sti		r4, 64, %112
# # sti		r4, 64, %112
# # sti		r4, 64, %112
# # sti		r4, 64, %112
# # sti		r4, 64, %112
# # sti		r4, 64, %112

# 3

