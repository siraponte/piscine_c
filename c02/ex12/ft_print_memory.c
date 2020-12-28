/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:10:57 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/03 10:23:28 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_string(char *addr, unsigned int count, unsigned int cursor)
{
	unsigned int	counter;

	counter = cursor;
	cursor = 16 - cursor;
	if (cursor == 0)
		cursor = 1;
	else if (cursor == 1)
		cursor = 3;
	else
		cursor = (cursor * 2) + (cursor / 2) + 1;
	while (cursor-- > 0)
		write(1, " ", 1);
	while (counter > 0)
	{
		if (addr[count - counter] >= 32 && addr[count - counter] < 127)
			write(1, &addr[count - counter], 1);
		else
			write(1, ".", 1);
		counter--;
	}
	write(1, "\n", 1);
}

void	write_content(char *addr, unsigned int count)
{
	unsigned int	address;
	char			*hex;

	hex = "0123456789abcdef";
	address = (unsigned char)addr[count];
	if (address / 16 != 0)
	{
		write(1, &hex[address / 16], 1);
		write(1, &hex[address % 16], 1);
	}
	else
	{
		write(1, "0", 1);
		write(1, &hex[address], 1);
	}
}

void	write_address(unsigned long address)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (address / 16 != 0)
	{
		write_address(address / 16);
		write(1, &hex[address % 16], 1);
	}
	else
		write(1, &hex[address], 1);
}

void	full_address(void *addr, unsigned int count, unsigned int cursor)
{
	unsigned long		address;
	unsigned long		fake_address;
	unsigned int		counter;

	address = (unsigned long)(addr + count);
	if (address >= 0xffffffff00000000)
		address -= 0xffffffff00000000;
	fake_address = address;
	counter = 0;
	while (fake_address / 16 != 0)
	{
		fake_address /= 16;
		counter++;
	}
	if (count != 0)
		write_string(addr, count, cursor);
	while (counter++ < 15)
		write(1, "0", 1);
	write_address(address);
	write(1, ":", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	count;
	unsigned int	cursor;

	cursor = 0;
	count = 0;
	while (count < size)
	{
		if (count % 16 == 0)
		{
			full_address(addr, count, cursor);
			cursor = 0;
		}
		if (count % 2 == 0 && count != 1)
			write(1, " ", 1);
		write_content(addr, count);
		cursor++;
		count++;
	}
	if (size > 0)
		write_string(addr, count, cursor);
	return (addr);
}
