# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sivinska <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 15:21:02 by sivinska          #+#    #+#              #
#    Updated: 2018/06/26 14:11:01 by sivinska         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INC = -I. -I./ft_printf

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
	ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_convert_to_base.c\
	ft_convert_to_base_long.c ft_str_to_upper.c ft_strrev.c\
	ft_get_nbr_len.c ft_putnbr_unsigned.c ft_putchar_ret.c \
	ft_putchar_unicode.c ft_put_nbr_longlong.c ft_unicode_len.c \
	ft_atoi_longlong.c ft_pow.c ft_get_nbr_len_unsigned.c \
	get_next_line.c ft_atoi_signed.c

PRINTF_DIR = ft_printf/
PRINTF_SRC = char.c check_line.c flags.c helper.c hex.c integer.c long_char.c \
			 long_string.c octal.c percent.c pointer.c print.c recheck_flags.c \
			 rules.c string.c unsigned.c free_memory.c flag_type.c \
			 send_strings.c

PRINTF_OBJS = $(PRINTF_SRC:.c=.o)
PRINTF_OBJ_SRC = $(addprefix $(PRINTF_DIR),$(PRINTF_SRC))

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) $(PRINTF_OBJ_SRC) $(INC)
	@ar rc $(NAME) $(OBJ) $(PRINTF_OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJ) $(PRINTF_OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
