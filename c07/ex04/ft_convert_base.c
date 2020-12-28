#include <stdlib.h>

int     ft_is_base_valid(char *base, int index, int index2);
int		ft_is_in_base(char *base, int index, char c);
int		ft_numlen(long nbr, int baselen, int index);
void	ft_rev_char_tab(char *tab, int size);

int		ft_to_new_base(long nbr, char *base, char *tab, int index)
{
	int		baselen;
	
	baselen = ft_is_base_valid(base, 0, 0);
	if (nbr < 0)
		ft_to_new_base(-nbr, base, tab, index);
	else if (nbr >= baselen)
	{
		ft_to_new_base(nbr / baselen, base, tab, index + 1);
		ft_to_new_base(nbr % baselen, base, tab, index);
	}
	else
		tab[index] = base[nbr];
	return (index);
}

int     ft_to_decimal(char *str, char *base, int baselen)
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

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	decimal;
	int		index;
	char	*tab;
	
	if (!(ft_is_base_valid(base_from, 0, 0) > 1 && ft_is_base_valid(base_to, 0, 0) > 1))
		return (0);
	decimal = ft_to_decimal(nbr, base_from, ft_is_base_valid(base_from, 0, 0));
	if (!(tab = (char *)malloc(ft_numlen(decimal, ft_is_base_valid(base_to, 0, 0), 0) + (decimal > 0 ? 0 : 1) * sizeof(char))))
		return (0);
	index = ft_to_new_base(decimal, base_to, tab, 0);
	if (decimal < 0)
	{
		tab[ft_numlen(decimal, ft_is_base_valid(base_to, 0, 0), 0) + 1] = '-';
		ft_rev_char_tab(tab, ft_numlen(decimal, ft_is_base_valid(base_to, 0, 0), 0) + 2);
	}
	else
		ft_rev_char_tab(tab, ft_numlen(decimal, ft_is_base_valid(base_to, 0, 0), 0));
	return (tab);
}