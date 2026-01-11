CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft_test
LIBUNIT_FOLDER = ../framework/
LIBUNIT_FILE = $(LIBUNIT_FOLDER)libunit.a

SRC = tests/main.c \
		tests/is_int/00_launcher.c \
		tests/is_int/01_is_int.c \
		tests/memchr/00_launcher.c \
		tests/memchr/01_memchr_can_find_d_in_abcdef_test.c \
		tests/memchr/02_memchr_return_null_for_z_in_abcdef_test.c \
		tests/memchr/03_memchr_return_null_for_letter_after_n.c \
		tests/memchr/04_memchr_return_first_b_in_abababab.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libunit $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBUNIT_FILE)

test: all
	./$(NAME)

libunit:
	@make -C $(LIBUNIT_FOLDER)

clean:
	@rm -vf $(OBJS)
	make -C $(LIBUNIT_FOLDER) clean

fclean: clean
	@rm -vf $(NAME)
	make -C $(LIBUNIT_FOLDER) fclean

re: fclean all

.PHONY: all $(NAME) libunit clean fclean re
