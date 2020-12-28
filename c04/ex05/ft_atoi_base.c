/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:26:18 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/05 19:27:28 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_is_in_base(char *base, int index, char c)
{
	while (base[index] != '\0')
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int     ft_find_number(char *str, char *base, int baselen)
{
	int		index;
	int		sign;
	long	number;
	
	sign = 1;
	number = 0;
	index = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t' 
	|| str[index] == '\v' || str[index] == '\r' || str[index] == '\f')
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (ft_is_in_base(base, 0, str[index]) != -1)
	{
		number *= baselen;
		number += ft_is_in_base(base, 0, str[index]);
		index++;
	}
	return (number * sign);
}
	
int     ft_is_base_valid(char *base, int index)
{
	int		duplicate;
	int		match;
	
	while (base[index] != '\0')
	{
		if (base[index] == ' ' || base[index] == '\n' || base[index] == '\t'
	    || base[index] == '\v' || base[index] == '\r' || base[index] == '\f'
	    || base[index] == '+' || base[index] == '-')
			return (0);
		duplicate = 0;
		match = 0;
		while (base[duplicate] != '\0')
		{
			if (base[index] == base[duplicate])
				match++;
			duplicate++;
		}
		if (match > 1)
			return (0);
		index++;
	}
	return (index);
}

int		ft_atoi_base(char *str, char *base)
{
    if (ft_is_base_valid(base, 0) > 1)
        return (ft_find_number(str, base, ft_is_base_valid(base, 0)));
    return (0);
}

