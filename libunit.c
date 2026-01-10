/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:02:13 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/10 23:49:22 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>

int	print_result(char *title, t_unode test)
{
	pid_t f;
	int status;

	f = fork();
	if (f < 0)
	{
		ft_printf_err("%s:\t%s:\tLaunch test error.\n", title, test->name);
		return (0);
	}
	else if (!f)
	{
		// Child
		if (!test->function())
			exit(EXIT_OK);
		exit(EXIT_KO);
	}
	// Parent
	wait(&status);
	if (status == EXIT_OK)
		return (ft_printf("%s:\t%s:\t[OK]\n", title, test->name), 1);
	else if (status == EXIT_KO)
		ft_printf("%s:\t%s:\t[KO]\n", title, test->name);
	else if (status == SEG_FAULT)
		ft_printf("%s:\t%s:\t[SEGV]\n", title, test->name);
	else if (status == BUS_ERROR)
		ft_printf("%s:\t%s:\t[BUSERR]\n", title, test->name);
	return (0);
}

int	launch_tests(char *title, t_list *list)
{
	t_list	*node;
	t_unode	*content;
	int		counter;
	int		total;

	// if !*lst what to do???
	counter = 0;
	total = 0;
	while (list != NULL)
	{
		node = ft_lst_pop_front(&list);
		content = (t_unode *)node->content;
		counter += print_result(title, content);
		ft_lst_clear_basic(&node);
		total++;
	}
	ft_printf("%i/%i tests checked\n", counter, total);
	return (0);
}

void load_test(t_list *list, char *name, int (*function)(void))
{

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
