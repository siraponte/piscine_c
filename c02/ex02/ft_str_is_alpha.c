/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:33:53 by cserapon          #+#    #+#             */
/*   Updated: 2020/11/29 19:52:31 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		if (!(str[count] >= 'a' && str[count] <= 'z'))
			if (!(str[count] >= 'A' && str[count] <= 'Z'))
				return (0);
		count++;
	}
	return (1);
}
