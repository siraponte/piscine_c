/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:01:58 by cserapon          #+#    #+#             */
/*   Updated: 2020/12/06 14:00:01 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#define MAX 4

void	ft_print(int **matrix);

bool	ft_ver_bound(int **bounds, int **matrix, int col, int r)
{
	int		greatest;
	int		view;

	view = 1;
	greatest = matrix[r][col];
	while (r++ < MAX - 1)
		if (greatest < matrix[r][col])
		{
			greatest = matrix[r][col];
			view++;
		}
	if (!(bounds[0][col] == view))
		return (false);
	view = 1;
	r = 3;
	greatest = matrix[r][col];
	while (r-- > 0)
		if (greatest < matrix[r][col])
		{
			greatest = matrix[r][col];
			view++;
		}
	if (!(bounds[1][col] == view))
		return (false);
	return (true);
}

bool	ft_hor_bound(int **bounds, int **matrix, int row, int c)
{
	int		greatest;
	int		view;

	view = 1;
	greatest = matrix[row][c];
	while (c++ < MAX - 1)
		if (greatest < matrix[row][c])
		{
			greatest = matrix[row][c];
			view++;
		}
	if (!(bounds[2][row] == view))
		return (false);
	view = 1;
	c = 3;
	greatest = matrix[row][c];
	while (c-- > 0)
		if (greatest < matrix[row][c])
		{
			greatest = matrix[row][c];
			view++;
		}
	if (!(bounds[3][row] == view))
		return (false);
	return (true);
}

bool	ft_sudoku(int **matrix, int row, int col, int n)
{
	int		r;
	int		c;

	c = 0;
	r = 0;
	while (c < MAX)
	{
		if (matrix[row][c] == n)
			return (false);
		c++;
	}
	while (r < MAX)
	{
		if (matrix[r][col] == n)
			return (false);
		r++;
	}
	return (true);
}

bool	ft_backtracking(int **bounds, int **matrix, int row, int col)
{
	int		n;

	n = 1;
	if (row == MAX - 1)
		if (!ft_ver_bound(bounds, matrix, col - 1, 0))
			return (false);
	if (col == MAX)
	{
		if (!ft_hor_bound(bounds, matrix, row++, 0))
			return (false);
		col = 0;
	}
	if (row == MAX)
		return (true);
	while (n++ < MAX + 1)
	{
		if (ft_sudoku(matrix, row, col, n - 1))
		{
			matrix[row][col] = n - 1;
			if (ft_backtracking(bounds, matrix, row, col + 1))
				return (true);
		}
		matrix[row][col] = 0;
	}
	return (false);
}

bool	ft_matrix(int **bounds)
{
	int		**matrix;

	matrix = (int **)malloc(4 * sizeof(int *));
	matrix[0] = (int *)malloc(4 * sizeof(int));
	matrix[1] = (int *)malloc(4 * sizeof(int));
	matrix[2] = (int *)malloc(4 * sizeof(int));
	matrix[3] = (int *)malloc(4 * sizeof(int));
	matrix[4] = (int *)malloc(1 * sizeof(int));
	matrix[4] = 0;
	if (!ft_backtracking(bounds, matrix, 0, 0))
	{
		free(matrix);
		return (false);
	}
	ft_print(matrix);
	return (true);
}
