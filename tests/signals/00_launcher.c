/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 21:43:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int	signal_launcher(void)
{
	t_list	*list;

	list = NULL;
	load_test(&list, "signal ok", &signal_ok_test);
	load_test(&list, "signal ko", &signal_ko_test);
	load_test(&list, "signal seg fault", &signal_segmentation_fault_test);
	load_test(&list, "signal bus error", &signal_bus_error_test);
	return (launch_tests("SIGNAL", list));
}
