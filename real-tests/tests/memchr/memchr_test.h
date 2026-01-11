/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   memchr_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:12:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 00:47:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMCHR_TEST_H
# define MEMCHR_TEST_H

# include "../../../framework/libunit.h"
# include "../../libft/libft.h"

int	memchr_launcher(void);
int	memchr_can_find_d_in_abcdef_test(void);
int	memchr_return_null_for_z_in_abcdef_test(void);
int	memchr_return_null_for_letter_after_n(void);
int	memchr_return_first_b_in_abababab(void);

#endif
