/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:47:58 by tghnassi          #+#    #+#             */
/*   Updated: 2026/01/12 02:45:09 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>

void	style_print(char *title, char *name, char *msg, char *color)
{
	ft_printf("%s%s%s:%s:%s%s%s\n", KCYN, title, KNRM, name, color, msg, KNRM);
}

void	print_checked(int counter, int total)
{
	int		red;
	int		green;
	char	*red_str;
	char	*green_str;

	green = ((float) counter / (float) total) * 120;
	red = 255 - green;
	if (counter == total)
		green = 255;
	if (!counter)
		red = 255;
	red_str = ft_itoa(red);
	green_str = ft_itoa(green);
	ft_printf("\n%s%s;%s%s%i/%i tests checked%s\n\n",
		KSTA, red_str, green_str, KEND, counter, total, KNRM);
	free(red_str);
	free(green_str);
}

void	print_final_counter(&s_count)
{
	
}