/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:12:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 04:48:36 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOL_H
# define ATOL_H

# include "../framework/libunit.h"
# include "../../libft.h"
# include <limits.h>

int	atol_launcher(t_count *final_count);
int	atol_basic_test(void);
int	atol_negative_test(void);
int	atol_max_test(void);
int	atol_min_test(void);
int	atol_zero_test(void);

#endif
