NAME = so_long
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror -ggdb
SOURCES = \
	checkmap.c \
	parsing.c \
	main.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
OBJS = $(SOURCES:.c=.o)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF) 

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft bonus

$(FT_PRINTF):
	make -C ft_printf all

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all
