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
	@make -C tests/ --no-print-directory

libft:
	@make -C $(LIBFT_FOLDER) --no-print-directory

clean:
	@rm -vf $(OBJS)
	make -C $(LIBFT_FOLDER) --no-print-directory clean
	make -C tests/ --no-print-directory clean

fclean: clean
	@rm -vf $(NAME)
	make -C $(LIBFT_FOLDER) --no-print-directory fclean
	make -C tests/ --no-print-directory fclean

re: fclean all

.PHONY: all $(NAME) libft clean fclean re test
