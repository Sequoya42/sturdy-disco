#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 17:48:47 by rbaum             #+#    #+#              #
#    Updated: 2015/06/12 22:24:47 by rbaum            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

CFLAG = -Wall -Werror -Wextra

NAME = libft.a

INC_PATH =	./inc/

OBJ_PATH = ./obj/

SRC_PATH = ./src/

SRC_NAME = ft_atoi.c		ft_bzero.c		ft_isalnum.c	ft_isalpha.c	\
    ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_itoa.c		\
	ft_memalloc.c	ft_memccpy.c	ft_memchr.c		ft_memcmp.c		\
    ft_memcpy.c		ft_memdel.c		ft_memmove.c	ft_memset.c		\
	ft_putchar.c    ft_putchar_fd.c	ft_putendl.c	ft_putendl_fd.c	\
    ft_putnbr.c		ft_putnbr_fd.c	ft_putstr.c		ft_putstr_fd.c	\
    ft_strcat.c		ft_strchr.c		ft_strclr.c		ft_strcmp.c		\
	ft_strcpy.c		ft_strdel.c		ft_strdup.c		ft_strequ.c		\
    ft_striter.c    ft_striteri.c	ft_strjoin.c    ft_strlcat.c	\
    ft_strlen.c		ft_strmap.c		ft_strmapi.c	ft_strncat.c	\
    ft_strncmp.c	ft_strncpy.c	ft_strnequ.c	ft_strnew.c		\
    ft_strnstr.c	ft_strrchr.c	ft_strsplit.c	ft_strstr.c		\
    ft_strsub.c		ft_strtrim.c	ft_strctrim.c	ft_tolower.c	\
    ft_toupper.c	ft_lstadd.c		ft_lstdel.c		ft_lstdelone.c	\
	ft_lstinter.c	ft_lstnew.c		ft_lstmap.c		get_next_line.c \
	ft_putnbrn.c	ft_putnbrendl.c	ft_strndup.c	ft_clear_tab.c	\
	ft_nb_tab.c		ft_split_char.c	ft_update_tab.c	ft_error.c		\
	ft_strdup_tab.c	debug.c			match.c			ft_base.c		\
	ft_is_blank.c	ft_print.c		ft_read.c		print_memory.c	\
	
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC =		$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =		$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@ar rcs $@ $^
			@echo "compile done !"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
			@mkdir -p $(OBJ_PATH)
			@$(CC) $(CFLAG) -I$(INC_PATH) -o $@ -c $<

clean:
			@rm -rf $(OBJ)
			@echo "clean done !"

fclean:		clean
			@rm -rf $(NAME)
			@echo "fclean done !"

re: 		fclean all