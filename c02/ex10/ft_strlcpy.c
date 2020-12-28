/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:12:49 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/02 15:43:35 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src)
{
	unsigned int	count;

	count = 0;
	while (src[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (size > 1)
	{
		if (count == size - 1 || src[count] == '\0')
			break ;
		dest[count] = src[count];
		count++;
	}
	if (size > 0)
		dest[count] = '\0';
	return (ft_strlen(src));
}
