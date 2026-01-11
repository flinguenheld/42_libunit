/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 22:11:07 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_int/is_int.h"

int	main(void)
{
	int	counter;

	counter = 0;
	counter += is_int_launcher();
	return (0);
}
