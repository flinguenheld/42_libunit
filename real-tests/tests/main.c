/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 01:33:55 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_int/is_int.h"
#include "lst_size/lst_size.h"
#include "atol/atol.h"
#include "memchr/memchr_test.h"

int	main(void)
{
	int	counter;

	counter = 0;
	counter += is_int_launcher();
	counter += lst_size_launcher();
	counter += atol_launcher();
	counter += memchr_launcher();
	return (0);
}
