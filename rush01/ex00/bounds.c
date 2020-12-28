/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:53:12 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/06 13:38:56 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ft_allocation(void)
{
	int		**bounds;

	bounds = (int **)malloc(4 * sizeof(int *));
	bounds[0] = (int *)malloc(4 * sizeof(int));
	bounds[1] = (int *)malloc(4 * sizeof(int));
	bounds[2] = (int *)malloc(4 * sizeof(int));
	bounds[3] = (int *)malloc(4 * sizeof(int));
	bounds[4] = (int *)malloc(1 * sizeof(int));
	bounds[4] = 0;
	return (bounds);
}

int		**ft_split(char *str)
{
	int		**bounds;
	int		bounds_index;
	int		str_index;
	int		number_index;

	bounds = ft_allocation();
	str_index = 0;
	bounds_index = 0;
	number_index = 0;
	while (str[str_index] != '\0')
	{
		if (number_index % 4 == 0 && number_index != 0)
		{
			//bounds[bounds_index][number_index] = 0;
			number_index = 0;
			bounds_index++;
		}
		if (str[str_index] != ' ')
		{
			bounds[bounds_index][number_index] = (int)str[str_index] - '0';
			number_index++;
		}
		str_index++;
	}
	return (bounds);
}
