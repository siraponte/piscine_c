/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:00:49 by cserapon          #+#    #+#             */
/*   Updated: 2020/11/29 16:27:04 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		count;
	int		ghost;

	count = 0;
	while (count < size / 2)
	{
		ghost = tab[count];
		tab[count] = tab[size - count - 1];
		tab[size - count - 1] = ghost;
		count++;
	}
}
