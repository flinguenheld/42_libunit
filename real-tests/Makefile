CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = real_test
LIBUNIT_FOLDER = ../framework/
LIBUNIT_FILE = $(LIBUNIT_FOLDER)libunit.a

SRC = tests/main.c \
		tests/is_int/00_launcher.c \
		tests/is_int/01_is_int.c \

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
