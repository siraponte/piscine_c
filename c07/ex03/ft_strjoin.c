/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:41:58 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/09 17:09:39 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_sepcat(char *sep, char *str, int str_index)
{
	int		index;

	index = 0;
	while (sep[index] != '\0')
	{
		str[str_index] = sep[index];
		str_index++;
		index++;
	}
	return (str_index);
}

int		ft_ultimate_strlen(char **strs, int size, int count, int index)
{
	int		ultimate_len;

	ultimate_len = 0;
	while (count < size)
	{
		index = 0;
		while (strs[count][index] != '\0')
		{
			index++;
		}
		count++;
	}
	return (ultimate_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		str_index;
	int		count;
	int		index;

	if (!(str = (char *)malloc(((ft_ultimate_strlen(strs, size, 0, 0) + 1) +
		ft_ultimate_strlen(&sep, 1, 0, 0) *
		(size - 1)) * sizeof(char))))
		return (0);
	str_index = 0;
	count = 0;
	while (count < size)
	{
		index = 0;
		while (strs[count][index] != '\0')
		{
			str[str_index] = strs[count][index];
			str_index++;
			index++;
		}
		if (count++ + 1 != size)
			str_index = ft_sepcat(sep, str, str_index);
	}
	str[str_index] = '\0';
	return (str);
}