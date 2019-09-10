.PHONY: clean $(NAME) fclean re all
#libmalloc/libft_malloc.so
LIB 	= libmalloc/libft_malloc.so -L libmalloc/libft/ -lft

NAME	= malloc_test

SRC		= 	srcs/main.c

INCLUDES =	includes/main.h \

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
		gcc -Wall -Wextra -Werror -g $(LIB) $(OBJ) -o $(NAME)

obj/%.o: src/%.c

		mkdir -p obj
		gcc -Wall -Wextra -Werror -c $< -o $@

clean:
		/bin/rm -rf obj/

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

test: re
		./$(NAME)

all: $(NAME)
