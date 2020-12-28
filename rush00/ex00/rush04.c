/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:52:45 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/29 12:07:53 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int col, int row, int x, int y)
{
	if ((row == 1 && col == 1) || ((row == y && col == x) && y != 1 && x != 1))
		ft_putchar('A');
	else if ((row == 1 && col == x) || (row == y && col == 1))
		ft_putchar('C');
	else if (row == 1 || col == 1 || row == y || col == x)
		ft_putchar('B');
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
