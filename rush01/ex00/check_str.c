/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:51:15 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/06 12:52:58 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_is_onefour(char n)
{
	if (n == '1' || n == '2' || n == '3' || n == '4')
		return (true);
	return (false);
}

bool	ft_check_str(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		if (count % 2 == 0)
		{
			if (!ft_is_onefour(str[count]))
				return (false);
		}
		else
		{
			if (str[count] != ' ')
				return (false);
		}
		count++;
	}
	if (count != 31)
		return (false);
	return (true);
}
