NAME = push_swap
LIBFT_A = libft/libft.a
SRCS = pushswap.c err_handler.c operations.c print_utils.c utils.c compare.c lists.c m_operations.c
#utils.c
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