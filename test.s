.name "test"
.comment "instruction test"



ld 251883523, r2
ld -301764605, r3
ld 436432899, r4
ld -50106365, r5
ld 386101251, r6
ld -117215229, r7
ld 318992387, r8
ld -167546877, r9
ld -234655741 ,r10
ld 251883523 ,r11
ld 436432899 ,r12
ld 386101251 ,r13
ld 318992387 ,r14


st r1, 110
st r2, 120
st r3, 130
st r4, 140
st r5, 150
st r6, 160
st r7, 170
st r8, 180
st r9, 190
st r10, 200
st r11, 210
st r12, 220
st r13, 230
st r14, 240


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

