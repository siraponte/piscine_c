/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:09:55 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/08 10:10:24 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_print_combo(int *queen)
{
	int		count;
	char	print;

	count = 0;
	while (count < 10)
	{
		print = queen[count] + '0';
		write(1, &print, 1);
		count++;
	}
	write(1, "\n", 1);
}

bool	ft_is_safe(int *queen, int actual, int other)
{
	while (other < actual)
	{
		if (queen[actual] == queen[other])
			return (false);
		if (queen[actual] > queen[other])
		{
			if (queen[actual] - queen[other] == actual - other)
				return (false);
		}
		else
		{
			if (queen[other] - queen[actual] == actual - other)
				return (false);
		}
		other++;
	}
	return (true);
}

int		ft_recursive_placement(int *queen, int col, int *count)
{
	queen[col] = 0;
	while (queen[col] < 10)
	{
		if (ft_is_safe(queen, col, 0))
		{
			if (col != 9)
				ft_recursive_placement(queen, col + 1, count);
			else
			{
				ft_print_combo(queen);
				(*count)++;
			}
		}
		queen[col]++;
	}
	return (*count);
}

int		ft_ten_queens_puzzle(void)
{
	int		queen[10];
	int		count;

	count = 0;
	return (ft_recursive_placement(queen, 0, &count));
}
