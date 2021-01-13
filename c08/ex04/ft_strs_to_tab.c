/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:06:57 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/11 16:18:44 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char				*ft_strdup(char *src)
{
	char	*str;
	int		count;

	if (!(str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (0);
	count = 0;
	while (src[count] != '\0')
	{
		str[count] = src[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ptr;
	int			index;

	index = 0;
	if (!(ptr = (struct s_stock_str *)malloc((ac + 1) *
					sizeof(struct s_stock_str))))
		return (0);
	while (index < ac)
	{
		ptr[index].size = ft_strlen(av[index]);
		ptr[index].str = av[index];
		ptr[index].copy = ft_strdup(av[index]);
		index++;
	}
	ptr[index].str = 0;
	ptr[index].size = 0;
	ptr[index].copy = 0;
	return (ptr);
}
