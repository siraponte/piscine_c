/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:39:50 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/02 17:40:07 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	max_negative(void)
{
	write(1, "-2147483648", 11);
}

void	ft_putnbr(int nb)
{
	char	print;

	if (nb == -2147483648)
		max_negative();
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb >= 0 && nb < 10)
	{
		print = nb + '0';
		write(1, &print, 1);
	}
}
