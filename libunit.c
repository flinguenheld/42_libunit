/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:02:13 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 10:51:37 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft/libft.h"



int	print_result(int status, char *title, t_unode *test)
{
	int		code;

	if (WIFEXITED(status))
	{
		// Child terminated normally with exit() or return.
		code = WEXITSTATUS(status);
		if (code == EXIT_OK)
			return (ft_printf("%s:\t%s:\t[OK]\n", title, test->name), 1);
		else if (code == EXIT_KO)
			return (ft_printf("%s:\t%s:\t[KO]\n", title, test->name), 0);
	}
	else if (WIFSIGNALED(status))
	{
		// Child terminated by a signal.
		code = WTERMSIG(status);
		if (code == SIGSEGV)
			return (ft_printf("%s:\t%s:\t[SEGV]\n", title, test->name), 0);
		else if (code == SIGBUS)
			return (ft_printf("%s:\t%s:\t[BUSERR]\n", title, test->name), 0);
	}
	return (ft_printf("%s:\t%s:\t[unknown error].\n", title, test->name), 0);
}

int	fork_to_test(char *title, t_unode *test)
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
			exit(EXIT_OK); ///////////////////////////////////// try free before exit???
		exit(EXIT_KO);
	}
	// Parent
	id_wait = wait(&status);
	return (print_result(status, title, test));
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
		counter += fork_to_test(title, content);
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
