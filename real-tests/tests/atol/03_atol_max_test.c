/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_atol_max_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:12:43 by tghnassi          #+#    #+#             */
/*   Updated: 2026/01/12 01:50:54 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atol.h"

int	atol_max_test(void)
{
	char	*str;

	str = ft_ltoa(LONG_MAX);
	if (atol(str) == LONG_MAX)
		return (free(str), 0);
	else
		return (free(str), -1);
}
