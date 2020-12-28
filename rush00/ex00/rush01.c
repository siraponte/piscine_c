/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:55:06 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/28 16:30:55 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int col, int row, int x, int y)
{
	if ((row == 1 && col == 1) || ((row == y && col == x) && y != 1 && x != 1))
		ft_putchar('/');
	else if ((row == 1 && col == x) || (row == y && col == 1))
		ft_putchar('\\');
	else if (row == 1 || col == 1 || row == y || col == x)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

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
			print(col, row, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
