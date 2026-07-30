# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aranirin <aranirin@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 21:21:18 by aranirin          #+#    #+#              #
#    Updated: 2026/05/05 00:11:29 by aranirin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	ft_push.c \
	ft_rotate.c \
	ft_rotate_reverse.c \
	ft_swap_a.c \
	algo_simple.c \
	ft_check_duplicate.c \
	ft_free_split.c \
	init.c \
	is_valid_format.c \
	utils.c \
	radix.c \
	chunk_sort.c \
	adaptive.c \
	flag.c \
	ft_printf_fd.c \
	bench.c \
	l_atoi.c \
	error.c \
	flag_utils.c \
	chunks_utils.c \
	radix_utils.c \
	
OBJ = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -Ilibft

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
