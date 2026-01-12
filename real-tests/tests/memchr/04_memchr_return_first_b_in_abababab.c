/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   04_memchr_return_first_b_in_abababab.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 00:47:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memchr_test.h"

int	memchr_return_first_b_in_abababab(void)
{
	char	*return_value;

	return_value = ft_memchr("abababab", 'b', 8);
	if (ft_memcmp(return_value, "bababab", 7) == 0)
		return (0);
	return (-1);
}
