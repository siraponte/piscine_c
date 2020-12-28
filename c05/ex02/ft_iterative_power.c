/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:28:52 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/08 17:58:01 by cserapon         ###   ########.fr       */
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