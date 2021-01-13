/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:05:47 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/12 07:50:41 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_base_valid(char *base, int index, int index2)
{
	while (base[index] != '\0')
	{
		if (base[index] == ' ' || base[index] == '\n' || base[index] == '\t'
		|| base[index] == '\v' || base[index] == '\r' || base[index] == '\f'
		|| base[index] == '+' || base[index] == '-')
			return (0);
		index2 = index + 1;
		while (base[index2] != '\0')
		{
			if (base[index] == base[index2])
				return (0);
			index2++;
		}
		index++;
	}
	return (index);
}

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

int		ft_numlen(long nbr, int baselen, int index)
{
	if (nbr < 0)
		nbr *= -1;
	while (nbr / baselen > 0)
	{
		nbr /= baselen;
		index++;
	}
	return (index);
}

void	ft_rev_char_tab(char *tab, int size)
{
	int		count;
	char	ghost;

	count = 0;
	while (count < size / 2)
	{
		ghost = tab[count];
		tab[count] = tab[size - count - 1];
		tab[size - count - 1] = ghost;
		count++;
	}
}
