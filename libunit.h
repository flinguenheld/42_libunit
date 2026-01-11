/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:07:14 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 10:42:12 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>

# define EXIT_OK 10
# define EXIT_KO 20

/**
 * @brief
 * Struct used to store data in lists
 */
typedef struct s_unode
{
	int		(*function)(void);
	char	*name;
}	t_unode;

/**
 * @brief
 * Add a new test in the list.
 */
void	load_test(t_list **list, char *name, int (*function)(void));

/**
 * @brief
 * Loop in the list an launch tests.
 * Free the list once at the end of the function
 * @return
 * 0 if all tests are OK
 * Otherwise 1
 */
int		launch_tests(char *title, t_list *list);

#endif
