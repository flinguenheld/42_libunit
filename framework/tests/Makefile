CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libunit_test
LIBUNIT_FOLDER = framework/
LIBUNIT_FILE = framework/libunit.a

SRC =	main.c \
		signals/00_launcher.c \
		signals/01_signal_ok_test.c \
		signals/02_signal_ko_test.c \
		signals/03_signal_segmentation_fault_test.c \
		signals/04_signal_bus_error_test.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libunit $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBUNIT_FILE)
	./$(NAME) || true

libunit:
	@make -C $(LIBUNIT_FOLDER)

clean:
	@rm -f $(OBJS)
	make -C $(LIBUNIT_FOLDER) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBUNIT_FOLDER) fclean

re: fclean all

.PHONY: all $(NAME) clean fclean re libunit
