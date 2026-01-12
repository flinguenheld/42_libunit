CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = name_of_your_test_executable
LIBUNIT_FOLDER = framework/ 
LIBUNIT_FILE = framework/libunit.a

SRC =	main.c \
		folder/01_unit_test_you_want.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libunit $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBUNIT_FILE)
	./$(NAME) || true

libunit:
	@make -C $(LIBUNIT_FOLDER)

clean:
	@rm -vf $(OBJS)
	make -C $(LIBUNIT_FOLDER) clean

fclean: clean
	@rm -vf $(NAME)
	make -C $(LIBUNIT_FOLDER) fclean

re: fclean all

.PHONY: all $(NAME) clean fclean re libunit
