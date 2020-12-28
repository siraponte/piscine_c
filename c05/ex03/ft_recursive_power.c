/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:33:41 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/08 20:35:02 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive(int nb, int power, int powered)
{
	if (power > 0)
		return (ft_recursive(nb, power - 1, powered *= nb));
	return (powered);
}

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (ft_recursive(nb, power, 1));
}
