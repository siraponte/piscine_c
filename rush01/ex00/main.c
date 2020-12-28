/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:49:13 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/06 13:41:17 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	ft_matrix(int **bounds);
bool	ft_check_bounds(int **bounds);
int		**ft_split(char *str);
bool	ft_check_str(char *str);
int		ft_error(int **bounds);

int		main(int argc, char **argv)
{
	int		**bounds;

	bounds = 0;
	if (argc != 2)
		return (ft_error(bounds));
	if (!ft_check_str(argv[1]))
		return (ft_error(bounds));
	bounds = ft_split(argv[1]);
	if (!ft_check_bounds(bounds))
		return (ft_error(bounds));
	if (!ft_matrix(bounds))
		return (ft_error(bounds));
	free(bounds);
	return (0);
}
