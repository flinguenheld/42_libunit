/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:07:14 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/10 23:14:09 by tghnassi         ###   ########.fr       */
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

# define EXIT_OK 0
# define EXIT_KO 1
# define SEG_FAULT 2
# define BUS_ERROR 3

typedef struct s_unode
{
	int		(*function)(void);
	char	*name;
}	t_unode;

#endif

/**
 * @brief
 * Add a new node in the list.
 */
void load_test(t_list *list, char *name, int (*function)(void));

/**
 * @brief
 * Loop in the list an launch tests.
 * @return
 * The number of succesful tests ?
 */
int	launch_tests(char *title, t_list *list);


/**
 * @brief
 * Malloc a new content
 * @return
 * unode struct ptr or NULL if malloc error
 */
t_unode *new_content(char *name, int (*function)(void));

