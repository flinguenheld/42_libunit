CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libunit.a
LIBFT_FOLDER = ./libft/
LIBFT_FILE = $(LIBFT_FOLDER)libft.a
TEST = main_test

SRC =	libunit.c \
		print.c\

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libft $(OBJS)
	@mv $(LIBFT_FILE) $(NAME)
	@ar rcs $(NAME) $(OBJS)

test: all
	$(CC) $(TEST).c $(NAME) -o $(TEST)
	./$(TEST)

test_no_flag: CFLAGS =
test_no_flag: test

libft:
	@make -C $(LIBFT_FOLDER)

clean:
	@rm -vf $(OBJS)
	make -C $(LIBFT_FOLDER) clean

fclean: clean
	@rm -vf $(NAME)
	@rm -vf $(TEST)
	make -C $(LIBFT_FOLDER) fclean

re: fclean all

.PHONY: all $(NAME) libft clean fclean re test test_no_flag
