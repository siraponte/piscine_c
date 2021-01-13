/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:34:47 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/09 11:34:52 by cserapon         ###   ########.fr       */
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
