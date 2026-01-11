/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 19:41:06 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real.h"

int	real_launcher(void)
{
	t_list	*list;

	list = NULL;
	load_test(&list, "real ok", &real_ok_test);
	load_test(&list, "real ko", &real_ko_test);
	load_test(&list, "segmentation fault", &real_segmentation_fault_test);
	load_test(&list, "bus error", &bus_error_test);
	return (launch_tests("REAL", list));
}
