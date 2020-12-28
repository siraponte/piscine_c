/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:17:29 by cserapon          #+#    #+#             */
/*   Updated: 2020/11/27 11:23:43 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(char first_f, char first_s, char second_f, char second_s)
{
	write(1, &first_f, 1);
	write(1, &first_s, 1);
	write(1, " ", 1);
	write(1, &second_f, 1);
	write(1, &second_s, 1);
	if (first_f != '9' || first_s != '8')
	{
		write(1, ", ", 2);
	}
}

void	converter(int first, int second)
{
	char first_f;
	char first_s;
	char second_f;
	char second_s;

	first_f = (char)first / 10 + 48;
	first_s = (char)first % 10 + 48;
	second_f = (char)second / 10 + 48;
	second_s = (char)second % 10 + 48;
	printer(first_f, first_s, second_f, second_s);
}

void	ft_print_comb2(void)
{
	int first;
	int second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			converter(first, second);
			second++;
		}
		first++;
	}
}
