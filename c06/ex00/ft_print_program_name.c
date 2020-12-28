/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:53:36 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/07 16:24:59 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		index;

	index = 0;
	if (argc == 1)
		while (argv[0][index] != '\0')
		{
			write(1, &argv[0][index], 1);
			index++;
		}
	write(1, "\n", 1);
	return (0);
}
