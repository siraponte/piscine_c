/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:24:52 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/03 10:14:22 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert(unsigned char c)
{
	unsigned int	converted;
	unsigned char	print;
	char			*hex;

	hex = "0123456789abcdef";
	converted = c;
	print = hex[converted / 16];
	write(1, &print, 1);
	print = hex[converted % 16];
	write(1, &print, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	count;
	unsigned char	character;

	count = 0;
	while (str[count] != '\0')
	{
		character = (unsigned char)str[count];
		if (!(character >= 32 && character < 127))
		{
			write(1, "\\", 1);
			convert(character);
		}
		else
			write(1, &character, 1);
		count++;
	}
}
