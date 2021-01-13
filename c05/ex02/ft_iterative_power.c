/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:34:11 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/09 11:34:20 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		powered;

	powered = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		powered *= nb;
		power--;
	}
	return (powered);
}
