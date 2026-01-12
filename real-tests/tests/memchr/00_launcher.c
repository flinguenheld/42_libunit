/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 00:47:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memchr_test.h"

int	memchr_launcher(void)
{
	t_list	*list;

	list = NULL;
	load_test(&list, "Finds d in abcde",
		&memchr_can_find_d_in_abcdef_test);
	load_test(&list, "Returns NULL for z in abcde",
		&memchr_return_null_for_z_in_abcdef_test);
	load_test(&list, "Returns NULL for letter after n",
		&memchr_return_null_for_letter_after_n);
	load_test(&list, "Returns the first b in abababab",
		&memchr_return_first_b_in_abababab);
	return (launch_tests("MEMCHR", list));
}
