/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:20:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 00:24:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libunit.h"

int an_awesome_dummy_test_function(void)
{
	if (ft_strlen("abcd") == 4)
		return (0);
	else
		return (-1);
}

int another_awesome_dummy_test_function(void)
{
	// if (10 * 2 == 0)
	// 	return (0);
	// else
		return (-1);
}

int segfault_test(void)
{
	char *a;
	*a = 5;
	return 1;
}

int main()
{
	t_list	*list;

	list = NULL;

	load_test(&list, "Awsome dummy function", &an_awesome_dummy_test_function);
	load_test(&list, "another dummy function", &an_awesome_dummy_test_function);
	load_test(&list, "segfault that!", &segfault_test);

	ft_printf("list len: %d\n", ft_lst_size(list));

	launch_tests("THEO TESTS", list);
}
