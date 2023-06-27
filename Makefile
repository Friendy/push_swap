NAME = push_swap
LIBFT_A = libft/libft.a
SRCS = push_swap.c err_handler.c operations.c utils.c indexate.c compare.c lists.c batch_ops.c checks.c convs.c stack_a.c arrs.c
FLAGS = -Werror -Wall -Wextra
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	cc -o $(NAME) $(OBJS) -Llibft -lft

$(OBJS):
	cc $(FLAGS) -c $(SRCS)

$(LIBFT_A): make_libft

make_libft:
	make -C libft

clean:
	make fclean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re