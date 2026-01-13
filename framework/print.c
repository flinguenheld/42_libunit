/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:47:58 by tghnassi          #+#    #+#             */
/*   Updated: 2026/01/13 19:52:44 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>

void	print_with_style(char *title, char *name, char *msg, char *color)
{
	ft_printf("%s%s - %s%s%s - %s%s\n", KGRE, title,
		KNRM, color, name, msg, KNRM);
}

void	print_local_counter(int counter, int total)
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
	ft_printf("\n%s%s;%s%s%i/%i tests successful%s\n\n",
		KSTA, red_str, green_str, KEND, counter, total, KNRM);
	free(red_str);
	free(green_str);
}

void	print_final_counter(t_count *s_count)
{
	ft_printf("%s255;0%s=========%s200;50%s=========%s150;100%s=========",
		KSTA, KEND, KSTA, KEND, KSTA, KEND);
	ft_printf("%s100;150%s=========%s50;200%s=========%s0;255%s=========\n",
		KSTA, KEND, KSTA, KEND, KSTA, KEND);
	ft_printf("%s255;0%sT%s200;50%sO%s150;100%sT",
		KSTA, KEND, KSTA, KEND, KSTA, KEND);
	ft_printf("%s100;150%sA%s50;200%sL%s0;255%s:%s",
		KSTA, KEND, KSTA, KEND, KSTA, KEND, KNRM);
	print_local_counter(s_count->success, s_count->total);
}
