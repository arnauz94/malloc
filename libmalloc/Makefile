# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avinas <avinas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 21:50:19 by avinas            #+#    #+#              #
#    Updated: 2019/09/12 16:56:14 by avinas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =		libft_malloc_$(HOSTTYPE).so

LINK =		libft_malloc.so

CC =		clang

FLAGS =		-Wall -Werror -Wextra -fPIC

LIB =		-L libft/ -lft

HEADERS =	-I ./include

SRC=   		src/allocator.c			\
			src/calloc.c			\
            src/free.c 				\
            src/malloc.c 			\
            src/page_manager.c		\
			src/realloc.c			\
			src/show_alloc_mem.c	\
			src/utils_type.c		\
			src/malloc_size.c		\
			src/reallocf.c

OBJ     = $(patsubst src/%.c,obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) $(OBJ) $(HEADERS) $(LIB) -shared -o $(NAME)
	@/bin/rm -f $(LINK)
	ln -fs $(NAME) $(LINK)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -rf obj/
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LINK)
	make -C libft/ fclean

re: fclean all

all: $(NAME)

