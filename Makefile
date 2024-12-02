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
# Compilation de l'exécutable final
$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	@cc $(FLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(LIBFLAGS) -o $(NAME)

# Compilation des fichiers objets
%.o: %.c
	@cc $(FLAGS) -c $< -o $@

# Compilation des bibliothèques tierces
$(LIBFT):
	@make -C libft bonus

$(FT_PRINTF):
	@make -C ft_printf all

$(MINILIBX):
	@make -C .minilibx-linux

# Cibles de nettoyage
clean:
	@rm -f $(OBJS)
	@make -C libft clean
	@make -C ft_printf clean
	@make -C .minilibx-linux clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@make -C ft_printf fclean
	@make -C .minilibx-linux clean

# Recompilation complète
re: fclean all
