/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:55:48 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/11 11:21:13 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *src)
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
