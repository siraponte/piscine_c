/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:48:40 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/07 14:45:43 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	count;

	count = 0;
	while (s1[count] == s2[count])
	{
		if (s1[count] == '\0' || s2[count] == '\0')
			break ;
		count++;
	}
	if ((unsigned char)s1[count] - (unsigned char)s2[count] > 0)
		return (true);
	return (false);
}

char	**ft_matrixswap(int argc, char **argv)
{
	int		index;
	int		other;
	char	*tmp;

	index = 1;
	while (index < argc)
	{
		other = index + 1;
		while (other < argc)
		{
			if (ft_strcmp(argv[index], argv[other]))
			{
				tmp = argv[index];
				argv[index] = argv[other];
				argv[other] = tmp;
			}
			other++;
		}
		index++;
	}
	return (argv);
}

int		main(int argc, char **argv)
{
	int		count;
	int		index;
	char	**matrix;

	if (argc < 2)
		return (0);
	matrix = ft_matrixswap(argc, argv);
	count = 1;
	while (count < argc)
	{
		index = 0;
		while (matrix[count][index] != '\0')
		{
			write(1, &matrix[count][index], 1);
			index++;
		}
		write(1, "\n", 1);
		count++;
	}
	return (0);
}
