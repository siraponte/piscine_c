/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:58:30 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/06 13:00:08 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_print(int **matrix)
{
	int		array_index;
	int		digits_index;
	char	print;

	array_index = 0;
	while (array_index != 4)
	{
		digits_index = 0;
		while (digits_index != 4)
		{
			print = (char)matrix[array_index][digits_index] + '0';
			write(1, &print, 1);
			if (digits_index < 3)
				write(1, " ", 1);
			digits_index++;
		}
		write(1, "\n", 1);
		array_index++;
	}
	free(matrix);
}
