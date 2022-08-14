# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 19:14:40 by aumarin           #+#    #+#              #
#    Updated: 2022/08/14 16:54:41 by aumarin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRC		= 	push_swap.c \
			includes/ft_atoi.c \
			includes/ft_isdigit.c \
			includes/ft_lstlast.c \
			includes/ft_lstsize.c \
			srcs/checker.c \
			srcs/stack_manager.c \
			srcs/moves.c \
			srcs/sort.c \
			srcs/find_actions.c

OBJ		=	$(SRC:.c=.o)
C_FLAG	=	-Wall -Wextra -Werror
CC		=	gcc

all: $(NAME)

.c.o:
	@echo "\033[0;33mcompiling... \033[0;37m"
	@$(CC) -o $@ -c $< $(C_FLAGS) -I .

$(NAME): $(OBJ)
	@echo "\033[0;33mlinking... \033[0;37m"	
	@$(CC)  $(C_FLAGS) -o $@ $^ includes/libftprintf.a

clean:
	@echo "\033[0;33mdeleting objects... \033[0;37m"
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "\033[0;33mdone \033[0;37m"

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all