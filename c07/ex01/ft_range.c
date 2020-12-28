/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:43:52 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/09 11:59:54 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		count;
	int		*tab;

	if (min >= max)
	{
		tab = 0;
		return (tab);
	}
	if (!(tab = (int *)malloc((max - min) * sizeof(int))))
		return (0);
	count = 0;
	while (min < max)
	{
		tab[count] = min;
		min++;
		count++;
	}
	return (tab);
}