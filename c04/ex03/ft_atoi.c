/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:41:32 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/06 18:55:02 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_is_space(char *str, int index)
{
	if (str[index] == ' ' || str[index] == '\n' || str[index] == '\t'
	|| str[index] == '\v' || str[index] == '\r' || str[index] == '\f')
		return (true);
	return (false);
}

bool	ft_is_sign(char *str, int index)
{
	if (str[index] == '+' || str[index] == '-')
		return (true);
	return (false);
}

bool	ft_is_number(char *str, int index)
{
	if (str[index] >= '0' && str[index] <= '9')
		return (true);
	return (false);
}

int		ft_atoi(char *str)
{
	int		index;
	int		sign;
	long		number;
	
	sign = 1;
	number = 0;
	index = 0;
	while (ft_is_space(str, index))
		index++;
	while (ft_is_sign(str, index))
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (ft_is_number(str, index))
	{
		number *= 10;
		number += str[index] - '0';
		index++;
	}
	return (number * sign);
}