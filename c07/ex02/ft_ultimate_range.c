/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:36:56 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/12 07:50:01 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	limit;
	int	index;
	int	*tab;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	limit = max - min;
	if (!(tab = malloc(limit * sizeof(int))))
	{
		*range = 0;
		return (-1);
	}
	*range = tab;
	index = 0;
	while (index < limit)
	{
		tab[index] = min + index;
		index++;
	}
	return (limit);
}
