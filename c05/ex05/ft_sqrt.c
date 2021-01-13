/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:35:56 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/09 11:35:59 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		rad;

	rad = 2;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	while (rad * rad != nb)
	{
		if (rad >= 46340)
			return (0);
		rad++;
	}
	return (rad);
}
