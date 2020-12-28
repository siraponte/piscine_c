/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 08:05:50 by cserapon          #+#    #+#             */
/*   Updated: 2020/11/28 11:07:50 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(int n, int digits[])
{
	int		count;
	char	print;

	count = 0;
	while (count < n)
	{
		print = digits[count] + '0';
		write(1, &print, 1);
		count++;
	}
	if (digits[0] != 10 - n)
		write(1, ", ", 2);
}

void	recursive(int n, int digits[], int actual_digit, int count)
{
	int limit;

	if (actual_digit == n)
		printer(n, digits);
	else
	{
		limit = 10 - (n - actual_digit);
		while (count + 1 <= limit)
		{
			digits[actual_digit] = count + 1;
			recursive(n, digits, actual_digit + 1, count + 1);
			count++;
		}
	}
}

void	ft_print_combn(int n)
{
	int digits[10];

	recursive(n, digits, 0, -1);
}
