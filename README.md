*This project has been created as part of the 42 curriculum by [tghnassi](https://kakaoarbo.net/), [flinguen](https://linguenheld.net/), khebert*

## Libunit

### Description

This project allows you to easily launch and print unit tests.  

### Installation

Clone this repository in the root of your project and name the folder **tests**.  
It will have this shape:  

```
- your_project/
        |-> Makefile
        |-- tests/
        |     |-> Makefile
        |     |-> main.c
        |     |-- framework/
        |     |-- function_to_test_1/
        |     |        |-> 00_launcher.c
        |     |        |-> 01_unit_test.c
        |     |        |-> 02_unit_test.c
        |     |        |-> function_to_test_1.h
        |     |-- function_to_test_2/
        |     |        |-> 00_launcher.c
        |     |        |-> 01_unit_test.c
        |     |        |-> 02_unit_test.c
        |     |        |-> function_to_test_2.h
```

#### Steps

1. Up *your* Makefile with a new rule:

``` Makefile
test: all
	@make -C tests/

.PHONY: all $(NAME) clean fclean re [...] test
```

2. Create a folder in *tests* with the name of a function you want to test.

3. Create files which will contains your test functions and a .h with their prototypes.  
here **atol/atol_basic_test.c** for instance.  

``` C
#include "atol.h"

int	atol_basic_test(void)
{
	if (atol("2") == 2)
		return (0);
	else
		return (-1);
}

```
4. Inside this new folder, create a `00_launcher.c` file.  
It will be in charge of launching your unit functions.  
Here an example:

``` C
#include "atol.h"

int	atol_launcher(t_count *final_count)
{
	t_list	*list;

	list = NULL;
	load_test(&list, "Test 2", &atol_basic_test); // Function ptr
	load_test(&list, "Test -2", &atol_negative_test);
	load_test(&list, "Test long max", &atol_max_test);
	...
	return (launch_tests("ATOL", list, final_count));
}

```
5. Then add a *main.c* which will be in charge of your launchers

``` C
#include "is_int/is_int.h"
#include "lst_size/lst_size.h"
#include "atol/atol.h"
#include "memchr/memchr_test.h"

int	main(void)
{
	t_count	s_count;

	s_count = count_init();
	is_int_launcher(&s_count);
	lst_size_launcher(&s_count);
	atol_launcher(&s_count);
	memchr_launcher(&s_count);
	print_final_counter(&s_count);
	if (s_count.success != s_count.total)
		return (-1);
	return (0);
}
```

### Commands

In your root folder, simply run:  
It will compile your project, compile your tests and the libunit framework and launch them.  

``` bash
make test
```
