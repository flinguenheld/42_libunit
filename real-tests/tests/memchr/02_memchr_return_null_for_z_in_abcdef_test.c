/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   02_memchr_return_null_for_z_in_abcdef_test.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 00:47:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memchr_test.h"

int	memchr_return_null_for_z_in_abcdef_test(void)
{
	char	*return_value;

	return_value = ft_memchr("abcdef", 'z', 6);
	if (return_value == NULL)
		return (0);
	return (-1);
}
