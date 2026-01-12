/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 23:56:54 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_size.h"

int	lst_size_launcher(void)
{
	t_list	*list;

	list = NULL;
	load_test(&list, "Test on 1", &lst_size_basic_test);
	load_test(&list, "Test on 99998", &lst_size_large_test);
	load_test(&list, "Null test", &lst_size_null_test);
	return (launch_tests("LST SIZE", list));
}
