NAME = pipex

CC = cc -g
CFLAGS = -Wall -Werror -Wextra

CFILES = main.c		\
		 utils.c	\
		 libft.c	\
		 ft_split.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(OFILES) $(NAME)

re: fclean all

.PHONY: all clean fclean re