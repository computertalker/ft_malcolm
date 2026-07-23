NAME = ft_malcolm
CC = clang
CFLAGS = -g -Wall -Wextra -Werror 
SRC = src/main.c \
      src/parse.c \
      src/init.c

OBJS = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
