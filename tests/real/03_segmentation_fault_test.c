/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   03_segmentation_fault_test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 19:41:06 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real.h"
#include <unistd.h>

int	real_segmentation_fault_test(void)
{
	int	*a;

	a = NULL;
	*a = 50;
	return (-1);
}
