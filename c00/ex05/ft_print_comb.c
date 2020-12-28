/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:27:38 by cserapon          #+#    #+#             */
/*   Updated: 2020/11/26 15:35:23 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_comb(void)
{
	char digit[3];
	char *last;

	last = "789";
	digit[0] = '0';
	while (digit[0] < '7')
	{
		digit[1] = digit[0] + 1;
		while (digit[1] <= '8')
		{
			digit[2] = digit[1] + 1;
			while (digit[2] <= '9')
			{
				write(1, digit, 3);
				write(1, ", ", 2);
				digit[2]++;
			}
			digit[1]++;
		}
		digit[0]++;
	}
	write(1, last, 3);
}
