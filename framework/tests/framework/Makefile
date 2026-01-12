CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libunit.a
LIBFT_FOLDER = ./libft/
LIBFT_FILE = $(LIBFT_FOLDER)libft.a

SRC =	libunit.c \
		print.c \
		counter.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libft $(OBJS)
	@mv $(LIBFT_FILE) $(NAME)
	@ar rcs $(NAME) $(OBJS)

test: all
	@make -C tests/

libft:
	@make -C $(LIBFT_FOLDER)

clean:
	@rm -f $(OBJS)
	make -C $(LIBFT_FOLDER) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT_FOLDER) fclean

re: fclean all

.PHONY: all $(NAME) libft clean fclean re test
