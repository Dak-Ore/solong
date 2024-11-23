NAME = Test
SRCS = test.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	cc -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	cc $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all
