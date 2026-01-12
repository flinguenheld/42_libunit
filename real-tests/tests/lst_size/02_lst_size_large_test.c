/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_lst_size_large_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:20:47 by tghnassi          #+#    #+#             */
/*   Updated: 2026/01/12 01:48:36 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_size.h"

int	lst_size_large_test(void)
{
	int 	i;
	t_list	*lst;

	i = 99999;
	lst = NULL;
	while (--i > 0)
		ft_lst_push_front(&lst, ft_lst_new(NULL));
	if (ft_lst_size(lst) == 99998)
	{
		ft_lst_clear_basic(&lst);
		return (0);
	}
	else
	{
		ft_lst_clear_basic(&lst);
		return (-1);
	}
}
