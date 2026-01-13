/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:07:14 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/13 22:30:13 by flinguen         ###   ########.fr       */
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

# define EXIT_OK 1
# define EXIT_KO 0

# define KNRM  "\x1B[0m"
# define KSTA  "\x1B[38;2;"
# define KEND  ";0m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KGRAD0_GRN  "\x1B[38;2;0;200;0m"
# define KGRAD6_RED  "\x1B[38;2;200;200;0m"
# define KGRAD9_RED  "\x1B[38;2;200;0;0m"

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
 * Struct used to store result counter
 */
typedef struct s_count
{
	int		total;
	int		success;
}	t_count;

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
int		launch_tests(char *title, t_list *start_list, t_count *final_count);

/**
 * @brief
 * Print the given msg with all format options and clear them at the end
 */
void	print_with_style(char *name, char *msg, char *color);

/**
 * @brief
 * Print the counter for one launcher with an adapted colour
 */
void	print_local_counter(int counter, int total);

/**
 * @brief
 * Print the final counter with an adapted colour
 */
void	print_final_counter(t_count *s_count);

/**
 * @brief
 * Print a title on the left with a lot of ====
 */
void	print_title(char *title);

/**
 * @brief
 * Init a new counter with values to 0
 */
t_count	counter_init(void);

#endif
