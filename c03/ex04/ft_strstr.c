/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:27:36 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/06 17:18:40 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		count;
	int		count2;

	if (*to_find == 0)
		return (str);
	count = 0;
	while (str[count] != '\0')
	{
		count2 = 0;
		while (str[count + count2] == to_find[count2])
		{
			if (to_find[count2 + 1] == '\0')
				return (str + count);
			count2++;
		}
		count++;
	}
	return (0);
}
