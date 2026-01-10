/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:20:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/10 19:20:56 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	ft_printf("hello");

	ft_printf("pid of fork with getpid: %d\n", getpid());
	pid_t pid = fork();

	ft_printf("value : %b\n", -1);

	if (pid == 0)
	{
		ft_printf("Only printed by the child %d\n", getpid());
		sleep(2);

		// FORCE SEGFAULT
		int *a;
		ft_printf("aaa%c\n", *a);

		
		// exit(EXIT_SUCCESS);
		// exit(SIGEV_SIGNAL);
		// exit(BUS_ADRERR);
		// exit(EXIT_FAILURE);
		exit(SIGCHLD);
		// exit(5);
	}
	else
	{
		// int *value_child = malloc(sizeof(int));
		// *value_child = 10;
		int value_child;
		pid_t id = wait(&value_child);

		// value_child = value_child & 0xFF;
		value_child = value_child >> 8;

		ft_printf("value from child after wait: %d -> %d\n",id, value_child);
		// printf("value from child after wait: %d -> %b\n",id, *value_child & 0xFF);

		if (value_child == 5)
			ft_printf("ok that's the same signal\n");
		
	}
	
	ft_printf("pid of fork with getpid: %d - %d\n",pid, getpid());
}
