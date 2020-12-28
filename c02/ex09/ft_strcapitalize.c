/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:55:12 by cserapon          #+#    #+#             */
/*   Updated: 2020/11/30 17:58:29 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	true_(char *str, int count)
{
	if (str[count] >= 'A' && str[count] <= 'Z')
		return (false);
	else if (str[count] >= 'a' && str[count] <= 'z')
	{
		str[count] -= 32;
		return (false);
	}
	else
		return (true);
}

bool	false_(char *str, int count)
{
	if (str[count] >= 'A' && str[count] <= 'Z')
		str[count] += 32;
	if (!(str[count] >= 'a' && str[count] <= 'z'))
		if (!(str[count] >= '0' && str[count] <= '9'))
			return (true);
	return (false);
}

char	*ft_strcapitalize(char *str)
{
	int		count;
	bool	new_word;

	new_word = true;
	count = 0;
	while (str[count] != '\0')
	{
		if (new_word)
		{
			if (str[count] >= '0' && str[count] <= '9')
				new_word = false;
			else
				new_word = true_(str, count);
		}
		else
		{
			new_word = false_(str, count);
		}
		count++;
	}
	return (str);
}
