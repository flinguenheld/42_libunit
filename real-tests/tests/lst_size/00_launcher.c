/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 01:48:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_size.h"

int	lst_size_launcher(void)
{
	t_list	*list;

	list = NULL;
	load_test(&list, "Test on size of 1", &lst_size_basic_test);
	load_test(&list, "Test on size of 99999", &lst_size_large_test);
	load_test(&list, "NULL list is size 0", &lst_size_null_test);
	return (launch_tests("LST SIZE", list));
}
