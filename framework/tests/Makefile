CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = signal_test
PARENT_FOLDER = ../
LIB_TO_TEST = $(PARENT_FOLDER)libunit.a

SRC = main.c \
		signals/00_launcher.c \
		signals/01_signal_ok_test.c \
		signals/02_signal_ko_test.c \
		signals/03_signal_segmentation_fault_test.c \
		signals/04_signal_bus_error_test.c

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libunit $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB_TO_TEST)
	./$(NAME) || true

clean:
	@rm -vf $(OBJS)

fclean: clean
	@rm -vf $(NAME)

re: fclean all

.PHONY: all $(NAME) libunit clean fclean re
