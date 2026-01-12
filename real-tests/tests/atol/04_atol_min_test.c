/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_atol_min_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:12:43 by tghnassi          #+#    #+#             */
/*   Updated: 2026/01/12 01:51:01 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atol.h"

int	atol_min_test(void)
{
	char	*str;

	str = ft_ltoa(LONG_MIN);
	if (atol(str) == LONG_MIN)
		return (free(str), 0);
	else
		return (free(str), -1);
}
