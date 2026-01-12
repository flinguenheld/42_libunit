/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:12:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 03:12:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INT_H
# define IS_INT_H

# include "../../../framework/libunit.h"
# include "../../libft/libft.h"

int	is_int_launcher(t_count *final_count);
int	is_int_basic_int_test(void);
int	is_int_basic_non_int_test(void);
int	is_int_null_test(void);
int	is_int_signs_test(void);
int	is_int_space_test(void);
int	is_int_no_char_test(void);

#endif
