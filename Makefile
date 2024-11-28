NAME = so_long
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror -ggdb
SRC_DIR = .
OBJDIR = obj
SOURCES = \
    checkmap.c \
    parsing.c \
    main.c \
    get_next_line/get_next_line.c \
    get_next_line/get_next_line_utils.c
OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
OBJDIRS = $(sort $(dir./ $(OBJS)))

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJDIRS) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

all: $(NAME)

$(OBJDIRS):
	mkdir -p $@

$(OBJDIR)/%.o: %.c | $(OBJDIRS)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft all

$(FT_PRINTF):
	make -C ft_printf all

clean:
	rm -rf $(OBJDIR)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all