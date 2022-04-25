all:
	@gcc -Wall -Wextra -Werror push_swap.c includes/*.a -o pswap
	@echo "done"