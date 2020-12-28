/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:54:46 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/29 12:07:08 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int row;
	int col;

	row = 1;
	while (row <= y && x >= 0)
	{
		col = 1;
		while (col <= x)
		{
			if ((row == 1 && col == 1) || (row == y && col == x))
				ft_putchar('o');
			else if ((row == 1 && col == x) || (row == y && col == 1))
				ft_putchar('o');
			else if (col == 1 || col == x)
				ft_putchar('|');
			else if (row == 1 || row == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
