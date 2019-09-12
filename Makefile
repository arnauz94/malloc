.PHONY: clean $(NAME) fclean re all
#libmalloc/libft_malloc.so
LIB 	= libmalloc/libft_malloc.so -L libmalloc/libft/ -lft

NAME	= malloc_test

SRC		= 	srcs/main.c

INCLUDES =	includes/main.h \

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
		make -C libmalloc
		gcc -Wall -Wextra -Werror -g $(LIB) $(OBJ) -o $(NAME)
		

obj/%.o: src/%.c
		mkdir -p obj
		gcc -Wall -Wextra -Werror -c $< -o $@

clean:
		make -C libmalloc clean
		/bin/rm -rf obj/

fclean: clean
		make -C libmalloc fclean
		/bin/rm -f $(NAME)
		/bin/rm -Rf malloc_test.dSYM

re: fclean all

test: re
		./$(NAME)

all: $(NAME)
