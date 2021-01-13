/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:09:14 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/10 17:50:54 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_write_base(long nbr, char *base, int baselen)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_write_base(-nbr, base, baselen);
	}
	else if (nbr >= baselen)
	{
		ft_write_base(nbr / baselen, base, baselen);
		ft_write_base(nbr % baselen, base, baselen);
	}
	else
		write(1, &base[nbr], 1);
}

bool	ft_is_not_printable_or_sign(char *base, int index)
{
	if (base[index] == ' ' || base[index] == '\f' || base[index] == '\r'
			|| base[index] == '\n' || base[index] == '\t'
			|| base[index] == '\v' || base[index] == '+' || base[index] == '-')
		return (true);
	return (false);
}

int		ft_is_base_valid(char *base, int index)
{
	int		duplicate;

	while (base[index] != '\0')
	{
		if (ft_is_not_printable_or_sign(base, index))
			return (0);
		duplicate = index + 1;
		while (base[duplicate] != '\0')
		{
			if (base[index] == base[duplicate])
				return (0);
			duplicate++;
		}
		index++;
	}
	return (index);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_is_base_valid(base, 0) > 1)
		ft_write_base(nbr, base, ft_is_base_valid(base, 0));
}
