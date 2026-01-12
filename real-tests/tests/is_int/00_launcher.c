/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 03:12:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_int.h"

int	is_int_launcher(t_count *final_count)
{
	t_list	*list;

	list = NULL;
	load_test(&list, "Basic test with int", &is_int_basic_int_test);
	load_test(&list, "Basic test with non-int", &is_int_basic_non_int_test);
	load_test(&list, "Null test", &is_int_null_test);
	load_test(&list, "Sign test", &is_int_signs_test);
	load_test(&list, "Spaces test", &is_int_space_test);
	load_test(&list, "No char after spaces/sign test", &is_int_no_char_test);
	return (launch_tests("IS INT", list, final_count));
}
