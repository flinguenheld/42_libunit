/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 21:32:07 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals/signals.h"

int	main(void)
{
	int	counter;

	counter = 0;
	counter += signal_launcher();
	return (0);
}
