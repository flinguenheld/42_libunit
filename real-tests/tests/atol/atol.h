/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:12:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 01:00:23 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOL_H
# define ATOL_H

# include <limits.h>
# include "../../../framework/libunit.h"
# include "../../libft/libft.h"

int	atol_launcher(void);
int	atol_basic_test(void);
int	atol_negative_test(void);
int	atol_max_test(void);
int	atol_min_test(void);
int	atol_zero_test(void);
#endif
