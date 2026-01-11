CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = real_test
LIBUNIT_FOLDER = ../framework/
LIBUNIT_FILE = $(LIBUNIT_FOLDER)libunit.a

SRC = main.c \
		real/00_launcher.c \
		real/01_real_ok_test.c \
		real/02_real_ko_test.c \
		real/03_segmentation_fault_test.c \
		real/04_bus_error_test.c

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libunit $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBUNIT_FILE)

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
