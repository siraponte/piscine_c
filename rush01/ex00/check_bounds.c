/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:55:25 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/06 13:39:06 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_check_bounds(int **bounds)
{
	int		count;

	count = 0;
	while (count < 4)
	{
		if (!(bounds[0][count] + bounds[1][count] >= 3
					&& bounds[0][count] + bounds[1][count] <= 5))
			return (false);
		if (!(bounds[2][count] + bounds[3][count] >= 3
					&& bounds[2][count] + bounds[3][count] <= 5))
			return (false);
		count++;
	}
	return (true);
}
