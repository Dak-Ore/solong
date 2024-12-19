NAME = so_long
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
MINILIBX = .minilibx-linux/libmlx.a
FLAGS = -Wall -Wextra -Werror -ggdb
LIBFLAGS = -L./.minilibx-linux -L/usr/lib -lmlx -lX11 -lXext -lm -lz
SOURCES = \
	checkmap.c \
	parsing.c \
	main.c \
	init.c \
	event.c \
	utils.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	@cc $(FLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(LIBFLAGS) -o $(NAME)

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -s -C libft bonus

$(FT_PRINTF):
	@make -s -C ft_printf all

$(MINILIBX):
	@make -s -C .minilibx-linux

clean:
	@rm -f $(OBJS)
	@make -C libft clean
	@make -C ft_printf clean
	@make -C .minilibx-linux clean

fclean: clean
	@rm -f $(NAME)
	@make -s -C libft fclean
	@make -s -C ft_printf fclean
	@make -s -C .minilibx-linux clean

re: fclean all
