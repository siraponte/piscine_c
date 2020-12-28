/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:34:55 by cserapon          #+#    #+#             */
/*   Updated: 2020/11/29 11:39:45 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		if (!(str[count] >= 'a' && str[count] <= 'z'))
		{
			return (0);
		}
		count++;
	}
	return (1);
}
