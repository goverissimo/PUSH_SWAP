# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 20:34:51 by gverissi          #+#    #+#              #
#    Updated: 2023/09/27 17:11:23 by gverissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra 

LIBFT = libft.a

RM = rm -rf

SRC = src/instructions_s.c src/instructions.c src/list_utils_sec.c src/list_utils.c\
src/main.c src/simple_sorting.c src/sorting.c src/stack_op.c src/util_funcs.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@make -C libft
	@mv libft/$(LIBFT) .
	$(CC) $(CFLAGS) $(OBJ) -L. -lft -o push_swap

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft	
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all