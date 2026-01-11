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

/**
 * @brief
 * Malloc a new content
 * @return
 * unode struct ptr or NULL if malloc error
 */
static t_unode	*new_content(char *name, int (*function)(void))
{
	t_unode	*content;

	content = malloc(sizeof(t_unode));
	if (content != NULL)
	{
		content->name = name;
		content->function = function;
	}
	return (content);
}

/**
 * @brief
 * Print the test result according to the given status with this format:
 * [title]:[test->name]:[status]
 *
 * Use <sys/wait.h> macros to check first if the returned status is from
 *   - exit() or return() (OK & KO only in this project)
 *   - signal
 * Then use another macro to get the code value.
 * @return
 * - 1 if test is OK
 * - 0 for all other cases
 */
static int	print_result(int status, char *title, t_unode *test)
{
	int	code;

	if (WIFEXITED(status))
	{
		code = WEXITSTATUS(status);
		if (code == EXIT_OK)
			return (ft_printf("%s:%s:[OK]\n", title, test->name), 1);
		else if (code == EXIT_KO)
			return (ft_printf("%s:%s:[KO]\n", title, test->name), 0);
	}
	else if (WIFSIGNALED(status))
	{
		code = WTERMSIG(status);
		if (code == SIGSEGV)
			return (ft_printf("%s:%s:[SIGSEGV]\n", title, test->name), 0);
		else if (code == SIGBUS)
			return (ft_printf("%s:%s:[SIGBUS]\n", title, test->name), 0);
	}
	return (ft_printf("%s:%s:[unknown error].\n", title, test->name), 0);
}

/**
 * @brief
 * Create a fork to launch the test fuction.
 * The child emits a signal OK/KO with the exit fuction
 * Due to the exit, the child frees the ENTIRE list to avoid any leak.
 *
 * The parent process waits the end of its child, then prints the result.
 * @return
 * 1 if test is OK
 * 0 for all other cases
 */
static int	fork_to_test(char *title, t_unode *test, t_list **list_to_free)
{
	pid_t	id_fork;
	pid_t	id_wait;
	int		status;
	int		(*function_to_test)(void);

	id_fork = fork();
	if (id_fork < 0)
	{
		ft_printf_err("%s:\t%s:\tLaunch test error.\n", title, test->name);
		ft_lst_clear_basic(list_to_free);
		return (0);
	}
	else if (id_fork == 0)
	{
		function_to_test = test->function;
		ft_lst_clear_basic(list_to_free);
		if (function_to_test == 0)
			exit(EXIT_OK);
		exit(EXIT_KO);
	}
	id_wait = wait(&status);
	return (print_result(status, title, test));
}

int	launch_tests(char *title, t_list *start_list)
{
	int		total;
	int		counter;
	t_unode	*content;
	t_list	*current_node;

	total = 0;
	counter = 0;
	current_node = start_list;
	while (current_node != NULL)
	{
		content = (t_unode *)current_node->content;
		counter += fork_to_test(title, content, &start_list);
		current_node = current_node->next;
		total++;
	}
	ft_lst_clear_basic(&start_list);
	ft_printf("%i/%i tests checked\n", counter, total);
	if (counter == total)
		return (0);
	return (1);
}

void	load_test(t_list **list, char *name, int (*function)(void))
{
	ft_lst_push_back(list, ft_lst_new(new_content(name, function)));
}
