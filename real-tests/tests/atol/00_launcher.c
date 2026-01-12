/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 03:12:42 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atol.h"

int	atol_launcher(t_count *final_count)
{
	t_list	*list;

	list = NULL;
	load_test(&list, "Test 2", &atol_basic_test);
	load_test(&list, "Test -2", &atol_negative_test);
	load_test(&list, "Test long max", &atol_max_test);
	load_test(&list, "Test long min", &atol_min_test);
	load_test(&list, "Test 0", &atol_min_test);
	return (launch_tests("ATOL", list, final_count));
}
