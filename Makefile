#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/23 15:32:39 by rbaum             #+#    #+#              #
#    Updated: 2016/07/12 00:29:37 by rbaum            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY:			all, libft, clean, fclean, re

CC =			gcc

CFLAG =			-Wall -Wextra -Werror

NAME =			corewar

SRC_PATH =		./src/

OBJ_PATH =		./obj/

LIBFT_PATH =	./libft/

INC_PATH =		./inc/

SRC_NAME =		main.c\
				singleton.c\
				ft_format.c\
				put_champ_in_memory.c\
				write_memory.c\
				start_war.c\
				manage_players.c\
				hex_to_dec.c\
				op.c\
				live.c	ld.c	st.c	add.c\
				sub.c	and.c	or.c	xor.c\
				zjmp.c	ldi.c	sti.c	fork.c\
				lld.c	lldi.c	lfork.c	aff.c\


OBJ_NAME =		$(SRC_NAME:.c=.o)

LIBFT_NAME =	libft.a

INC_NAME =		vm.h

SRC =			$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =			$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIBFT =			$(addprefix $(LIBFT_PATH),$(LIBFT_NAME))

INC =			$(addprefix $(INC_PATH),$(INC_NAME))

INCLIBFT = 		$(LIBFT_PATH)inc


LIBFT_FLAG = 	-L$(LIBFT_PATH) -lft

all:			libft $(NAME) 

$(NAME):		$(OBJ)
				@$(CC) $(LIBFT_FLAG) -o $@ $^
				@echo "Done"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAG) -I$(INC_PATH) -I$(INCLIBFT) -o $@ -c $<

libft:			$(LIBFT)

$(LIBFT):		$(LIBFT_PATH)
				@make -C $(LIBFT_PATH)

clean:
				@make -C $(LIBFT_PATH) clean
				@rm -f $(OBJ)

fclean:			
				@rm -f $(OBJ)
				@make -C $(LIBFT_PATH) fclean
				@rm -f $(NAME)

re: 			fclean all