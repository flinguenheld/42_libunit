/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:02:13 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 00:24:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>

int	print_result(char *title, t_unode *test)
{
	pid_t	f;
	pid_t	id_wait;
	int		status;

	f = fork();
	if (f < 0)
	{
		ft_printf_err("%s:\t%s:\tLaunch test error.\n", title, test->name);
		return (0);
	}
	else if (!f)
	{
		// Child
		if (test->function() == 0)
			exit(EXIT_OK);
		exit(EXIT_KO);
	}
	// Parent
	id_wait = wait(&status);
	if (id_wait < 0)
		ft_printf("error >>>.!!!!!!!!!!!!!\n");
	ft_printf("value of status before >> %d\n", status);
	// status >>= 8;
	status &= 0xFF;
	// status >>= 8;
	ft_printf("value of status after >> %d\n", status);
	if (status == EXIT_OK)
		return (ft_printf("%s:\t%s:\t[OK]\n", title, test->name), 1);
	else if (status == EXIT_KO)
		ft_printf("%s:\t%s:\t[KO]\n", title, test->name);
	// else if (status == SIGSEGV)
	else if (status == 256)
		ft_printf("%s:\t%s:\t[SEGV]\n", title, test->name);
	// else if (status == BUS_ERROR)
	else if (status == 253)
		ft_printf("%s:\t%s:\t[BUSERR]\n", title, test->name);
	else
		ft_printf("hello %d\n", status);
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

void load_test(t_list **list, char *name, int (*function)(void))
{
	ft_lst_push_back(list, ft_lst_new(new_content(name, function)));
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
