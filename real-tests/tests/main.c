/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 03:31:47 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}
