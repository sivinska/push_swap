NAME_1 = checker

SRC = check_parameters.c \
	push_swap.c

OBJ = $(SRC:.c=.o)

INC = -I. -I./libft

FLAGS = -Wall -Wextra -Werror

all: $(NAME_1)

$(NAME_1): $(OBJ)
	make -C libft/
	gcc -c $(FLAGS) $(OBJ) $(INC) push_swap.c -o $(NAME_1)

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME_1)
	make fclean -C libft/

re: fclean all	
