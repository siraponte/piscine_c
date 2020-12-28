/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:18:27 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/08 17:47:14 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive(int nb, int factorial)
{
	if (nb > 0)
		return (ft_recursive(nb - 1, factorial *= nb));
	return (factorial);
}

int		ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	return (ft_recursive(nb, 1));
}

