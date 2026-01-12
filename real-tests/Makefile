CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft_test
LIBUNIT_FOLDER = ../framework/
LIBUNIT_FILE = $(LIBUNIT_FOLDER)libunit.a

SRC = tests/main.c \
		tests/is_int/00_launcher.c \
		tests/is_int/01_is_int_basic_int_test.c \
		tests/is_int/02_is_int_basic_non_int_test.c \
		tests/is_int/03_is_int_null_test.c \
		tests/is_int/04_is_int_signs_test.c \
		tests/is_int/05_is_int_space_test.c \
		tests/is_int/06_is_int_no_char_test.c \
		tests/lst_size/00_launcher.c \
		tests/lst_size/01_lst_size_basic_test.c \
		tests/lst_size/02_lst_size_large_test.c \
		tests/lst_size/03_lst_size_null_test.c \
		tests/atol/00_launcher.c \
		tests/atol/01_atol_basic_test.c \
		tests/atol/02_atol_negative_test.c \
		tests/atol/03_atol_max_test.c \
		tests/atol/04_atol_min_test.c \
		tests/atol/05_atol_zero_test.c \
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
