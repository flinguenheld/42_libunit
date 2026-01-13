CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libunit_tester.exe
LIBUNIT_FOLDER = framework/ 
LIBUNIT_FILE = framework/libunit.a

SRC =	main.c \
		your_folder/01_unit_test_you_want.c \
		your_folder/02_unit_test_you_want.c \
		another_folder/01_unit_test_you_want.c \
		...

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libunit $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBUNIT_FILE)
	./$(NAME) || true

libunit:
	@make -C $(LIBUNIT_FOLDER) --no-print-directory

clean:
	@rm -vf $(OBJS)
	@make -C $(LIBUNIT_FOLDER) --no-print-directory clean

fclean: clean
	@rm -vf $(NAME)
	@make -C $(LIBUNIT_FOLDER) --no-print-directory fclean

re: fclean all

.PHONY: all $(NAME) clean fclean re libunit
