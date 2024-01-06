NAME = push_swap
SRCS = push_swap.c handle_errors.c stack_a.c stack_b.c push_operation.c rotate_operation.c rrotate_operation.c sort_algo.c sort_three.c stack_init.c stack_utils.c swap_operation.c both_stacks.c
OBJS = $(SRCS:.c=.o)
CC = clang
CFLAGS = -g -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

%.o: %.c push_swap.h
	$(CC) -g $(CFLAGS) -c $< -g -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT_MAKEFILE)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

$(LIBFT_MAKEFILE):
	@make -C $(LIBFT_DIR)
