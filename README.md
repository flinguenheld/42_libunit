*This project has been created as part of the 42 curriculum by [tghnassi](https://kakaoarbo.net/), [flinguen](https://linguenheld.net/), khebert*

## Libunit

### Description

This project allows you to easily launch and print unit tests.  

### Installation

Clone this repository in the root of your project.  
Then inside the folder, create folders where you will add your tests.  

```

- your_project/
        |
        |-> tests/
        |     |-> Makefile
        |     |-> main.c
        |     |-> function_to_test_1/
        |     |        |-> 00_launcher.c/
        |     |        |-> 01_unit_test.c/
        |     |        |-> 02_unit_test.c/
        |     |-> function_to_test_2/
        |     |        |-> 00_launcher.c/
        |     |        |-> 01_unit_test.c/
        |     |        |-> 02_unit_test.c/

```

Then add a Makefile which will point
Here an example which allows you to use the command `make test` to compile and launch all tests:  

``` Makefile

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = signal_test
LIBUNIT_FOLDER = framework/
LIBUNIT_FILE = $(LIBUNIT_FOLDER)libunit.a

SRC = tests/main.c \
		tests/function_name/00_launcher.c \
		tests/function_name/01_test_a_function.c \
		tests/function_name/02_another_test.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libunit $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBUNIT_FILE)

test: all
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

.PHONY: all $(NAME) libunit clean fclean re test
```
