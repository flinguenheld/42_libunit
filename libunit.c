/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:02:13 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/10 23:50:15 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>

int	launch_tests(char *title, t_list *list)
{

	
	return (0);
}

void load_test(t_list *list, char *name, int (*function)(void))
{
	ft_lst_push_back(&list, ft_lst_new(new_content(name, function)));
}

t_unode *new_content(char *name, int (*function)(void))
{
	t_unode *content;

	content = malloc(sizeof(t_unode));
	if (content != NULL)
	{
		content->name = name;
		content->function = function;
	}
	return (content);
}
