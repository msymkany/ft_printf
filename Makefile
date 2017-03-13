#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 20:14:25 by msymkany          #+#    #+#              #
#    Updated: 2017/03/13 21:36:57 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c\
		manage_struct.c\
		arg_cast_conversion.c\
		convert_digit.c\
		convert_wchar.c\
		parce_it.c\
		print_it.c\
		print_order.c\
		put_txt.c\
		skip_flags.c\
		get_mod.c\
		print_char.c\
		print_str.c\

OBJECTS = $(SOURCE:.c=.o)

LIB_DIR = ./libft/

LIB_INC = ./libft/libft.h

HEAD = libftprintf.h

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB_DIR)libft.a
	ar rc $(NAME) $(OBJECTS) $(LIB_DIR)*.o
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(LIB_DIR) -I $(LIB_INC) -I $(HEAD)

$(LIB_DIR)libft.a:
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all
