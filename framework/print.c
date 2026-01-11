/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:47:58 by tghnassi          #+#    #+#             */
/*   Updated: 2026/01/11 18:05:37 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	style_print(char *title, char *name, char *msg, char *color)
{
	ft_printf("%s%s%s:%s:%s%s%s\n", KCYN, title, KNRM, name, color, msg, KNRM);
}

void	print_checked(int counter, int total)
{
	int	red;
	int	green;

	green = ((float) counter / (float) total) * 120;
	red = 255 - green;
	if (counter == total)
		green = 255;
	if (!counter)
		red = 255;
	ft_printf("\n%s%s;%s%s%i/%i tests checked%s\n",
		KSTA, ft_itoa(red), ft_itoa(green), KEND, counter, total, KNRM);
}
