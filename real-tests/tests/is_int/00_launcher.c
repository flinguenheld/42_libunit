/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 22:11:07 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_int.h"

int	is_int_launcher(void)
{
	t_list	*list;

	list = NULL;
	load_test(&list, "basic test", &is_int_basic_test);
	return (launch_tests("IS INT", list));
}
