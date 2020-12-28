/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 20:03:24 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/07 11:46:24 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		count;
	int		index;

	count = argc - 1;
	if (argc < 2)
		return (1);
	while (count > 0)
	{
		index = 0;
		while (argv[count][index] != '\0')
		{
			write(1, &argv[count][index], 1);
			index++;
		}
		write(1, "\n", 1);
		count--;
	}
	return (0);
}
