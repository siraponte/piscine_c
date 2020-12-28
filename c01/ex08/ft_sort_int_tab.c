/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:21:40 by cserapon          #+#    #+#             */
/*   Updated: 2020/11/29 16:47:35 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int		compared;
	int		other;
	int		ghost;

	compared = 0;
	while (compared < size)
	{
		other = 0;
		while (other < size)
		{
			if (tab[compared] < tab[other])
			{
				ghost = tab[compared];
				tab[compared] = tab[other];
				tab[other] = ghost;
			}
			other++;
		}
		compared++;
	}
}
