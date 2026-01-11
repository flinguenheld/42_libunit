/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:07:14 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 18:06:10 by tghnassi         ###   ########.fr       */
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

# define KNRM  "\x1B[0m"
# define KSTA  "\x1B[38;2;"
# define KEND  ";0m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KGRAD0_GRN  "\x1B[38;2;0;255;0m"
# define KGRAD6_RED  "\x1B[38;2;170;85;0m"
# define KGRAD9_RED  "\x1B[38;2;255;0;0m"

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
 * Loop in the list and launch tests.
 * Free the list once at the end of the function
 * @return
 * 0 if all tests are OK
 * Otherwise 1
 */
int		launch_tests(char *title, t_list *list);

void	style_print(char *title, char *name, char *msg, char *color);
void	print_checked(int counter, int total);

#endif
