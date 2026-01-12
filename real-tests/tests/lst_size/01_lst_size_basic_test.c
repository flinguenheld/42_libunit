/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lst_size_basic_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:20:47 by tghnassi          #+#    #+#             */
/*   Updated: 2026/01/12 02:07:52 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_size.h"

int	lst_size_basic_test(void)
{
	int		is_ok;
	t_list	*lst;

	lst = NULL;
	ft_lst_push_front(&lst, ft_lst_new(NULL));
	if (ft_lst_size(lst) == 1)
		is_ok = 0;
	else
		is_ok = -1;
	ft_lst_clear_basic(&lst);
	return (is_ok);
}
