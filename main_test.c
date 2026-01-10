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
#include "libunit.h"

int an_awesome_dummy_test_function(void)
{
	if (ft_strlen("abcd") == 4)
		return (0);
	else
		return (-1);
}

int another_awesome_dummy_test_function(void)
{
	if (10 * 2 == 0)
		return (0);
	else
		return (-1);
}

int main()
{
	t_list *list;
	t_list *current_node;
	t_unode *current_content;


	// Add those two functions in the list
	list = NULL;
	ft_lst_push_back(&list, ft_lst_new(new_content("awsesome test", &an_awesome_dummy_test_function)));
	ft_lst_push_back(&list, ft_lst_new(new_content("another awsesome test", &another_awesome_dummy_test_function)));

	// Lauch tests
	while (list != NULL)
	{

		current_node = ft_lst_pop_front(&list);
		current_content = (t_unode *)current_node->content;

		ft_printf("%s\n", current_content->name);
		if (current_content->function() == 0)
		{
			ft_printf("That's a success\n");
		}
		else
		{
			ft_printf("That's a fail\n");
		}

		ft_lst_clear_basic(&current_node);
	}
}
