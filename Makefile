NAME = pipex
NAME_B = pipex_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES = src/pipex.c		\
		 src/path_utils.c	\
		 src/utils.c

CFILES_B =  bonus/pipex_bonus.c 		\
			bonus/path_utils_bonus.c	\
			bonus/utils_bonus.c			\

OFILES = $(CFILES:.c=.o)
OFILES_B = $(CFILES_B:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) -C libft/
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C libft/
	rm -f $(OFILES) $(OFILES_B)

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f $(OFILES) $(OFILES_B) $(NAME) $(NAME_B)

re: fclean all

bonus: $(NAME_B)

$(NAME_B): $(OFILES_B)
	$(MAKE) -C libft/
	$(CC) $(CFLAGS) $(OFILES_B) $(LIBFT) -o $(NAME_B)

re_bonus: fclean bonus

.PHONY: all bonus re re_bonus clean fclean
