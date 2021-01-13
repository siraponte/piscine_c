/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:32:04 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/09 11:32:34 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		factorial;

	factorial = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		factorial *= nb;
		nb--;
	}
	return (factorial);
}
