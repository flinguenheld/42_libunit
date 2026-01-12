/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lst_size_basic_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:20:47 by tghnassi          #+#    #+#             */
/*   Updated: 2026/01/11 23:44:29 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_size.h"

int	lst_size_basic_test(void)
{
	int 	i;
	t_list	*lst;

	i = 5;
	lst = ft_lst_new(&i);
	if (ft_lst_size(lst) == 1)
	{
		free(lst);
		return (0);
	}
	else
	{
		free(lst);
		return (-1);
	}
}
