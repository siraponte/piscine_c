/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:07:19 by cserapon          #+#    #+#             */
/*   Updated: 2020/11/26 11:29:35 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char print;

	if (n >= 0)
	{
		print = 'P';
	}
	else if (n < 0)
	{
		print = 'N';
	}
	write(1, &print, 1);
}
