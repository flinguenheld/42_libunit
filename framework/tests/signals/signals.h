/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:12:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 03:12:40 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "../framework/libunit.h"

int	signal_launcher(t_count *final_count);
int	signal_ok_test(void);
int	signal_ko_test(void);
int	signal_segmentation_fault_test(void);
int	signal_bus_error_test(void);

#endif
