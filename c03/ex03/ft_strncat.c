/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:34:14 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/03 16:51:49 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	count;
	unsigned int	count2;

	count = 0;
	while (dest[count] != '\0')
		count++;
	count2 = 0;
	while (count2 < nb && src[count2] != '\0')
	{
		dest[count + count2] = src[count2];
		count2++;
	}
	if (nb > 0)
		dest[count + count2] = '\0';
	return (dest);
}
