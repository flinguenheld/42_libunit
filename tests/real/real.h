/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   real.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:12:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 19:41:06 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_H
# define REAL_H

# include "../../framework/libunit.h"

int	real_launcher(void);
int	real_ok_test(void);
int	real_ko_test(void);
int	real_segmentation_fault_test(void);
int	bus_error_test(void);

#endif
