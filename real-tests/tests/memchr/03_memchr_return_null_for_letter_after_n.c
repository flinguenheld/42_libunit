/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   03_memchr_return_null_for_letter_after_n.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 00:47:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memchr_test.h"

int	memchr_return_null_for_letter_after_n(void)
{
	char	*return_value;

	return_value = ft_memchr("abcdefghijkl", 'h', 6);
	if (return_value == NULL)
		return (0);
	return (-1);
}
