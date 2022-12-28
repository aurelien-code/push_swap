# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 19:14:40 by aumarin           #+#    #+#              #
#    Updated: 2022/12/27 21:29:27 by aumarin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRC		= 	push_swap.c \
			srcs/checker.c \
			srcs/stack_manager.c \
			srcs/moves.c \
			srcs/sort.c \
			srcs/find_actions.c \
			srcs/ll_utils.c \
			srcs/parser.c

OBJ		=	$(SRC:.c=.o)
C_FLAG	=	-Wall -Wextra -Werror
CC		=	gcc

LIBFT_DIR = ./libft/
FT_PRINTF_DIR = ./ft_printf/

all: $(NAME)

.c.o:
	@echo "\033[0;33mcompiling... \033[0;37m"
	@$(CC) -o $@ -c $< $(C_FLAGS) -I .

$(NAME): $(OBJ)
	@echo "\033[0;33mlinking... \033[0;37m"	
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	@$(CC)  $(C_FLAGS) -o $@ $^ ./libft/libft.a ./ft_printf/libftprintf.a

clean:
	@echo "\033[0;33mdeleting objects... \033[0;37m"
	@rm -f $(OBJ) $(BONUS_OBJ)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	@echo "\033[0;33mdone \033[0;37m"

fclean: clean
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)

re: fclean all