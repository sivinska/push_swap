# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sivinska <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 16:02:10 by sivinska          #+#    #+#              #
#    Updated: 2018/09/25 15:24:58 by sivinska         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = checker

NAME_2 = push_swap

SRC = check_parameters.c commander.c  utilities.c smart_sorting.c \
	utilities2.c optimizer.c swap.c rotate.c reverse_rotate.c push.c parser.c \
	sort_big.c wipe_data.c median_and_average.c visual.c sorting_five.c \
	shortest_path.c push_smallest.c

OBJ = $(SRC:.c=.o)

INC = -I. -I./libft -I./libft/ft_printf
PUSHSWAP_H = push_swap.h

LIB_PATH = libft
LIB_LINK = -L $(LIB_PATH) -lft
LIB = $(LIB_PATH)/libft.a

FLAGS = -Wall -Wextra -Werror

all: colour $(NAME_1) $(NAME_2)
	@echo "Checker and push_swap created."

$(NAME_1): $(LIB) $(OBJ) checker.o
	@gcc $(FLAGS) -o $@ $^ $(LIB_LINK)

$(NAME_2): $(LIB) $(OBJ) push_swap.o
	@gcc $(FLAGS) -o $@ $^ $(LIB_LINK)
$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c $(PUSHSWAP_H)
	@gcc $(FLAGS) $(INC) -c -o $@ $<

colour:
	@echo "\x1b[1;32m"

clean:
	@rm -rf $(OBJ) push_swap.o checker.o
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME_1) $(NAME_2)
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re	
