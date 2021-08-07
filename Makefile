# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Konan <konagash@student.42tokyo.jp>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 00:52:07 by Konan             #+#    #+#              #
#    Updated: 2021/02/09 14:10:21 by konagash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/ft_printf.c \
       src/convert_base.c \
       src/parse_func.c \
       src/parse_char.c \
       src/parse_str.c \
       src/parse_int.c \
       src/parse_hex.c \
       src/parse_unsigned.c \
       src/parse_pointer.c \
       src/parse_persent.c \
       src/parse_utils.c \
       src/parse_flag.c

OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
