#include "ft_hexdump.h"

void	ft_print_address(int n, int fake_n, int counter, int max)
{
	while ((fake_n /= 16) != 0)
		counter++;
	while (counter++ < max)
		write(1, "0", 1);
	if (n / 16 != 0)
	{
		ft_print_address(n / 16, 7, 0, 0);
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else
		write(1, &"0123456789abcdef"[n], 1);
}

void	ft_adjust_output(char *buffer, int i, int j)
{
	while (j--)
		write(1, " ", 1);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] < 32 || buffer[i] > 126)
			buffer[i] = '.';
		i++;
	}
}

void	ft_print_with_flag(char *buffer, int print, int i, int max)
{
	ft_print_address(print, print, 0, 7);
	ft_putstr("  ");
	while (i < max)
	{
		if (i == 8)
			ft_putstr(" ");
		write(1, &"0123456789abcdef"[buffer[i] / 16], 1);
		write(1, &"0123456789abcdef"[buffer[i] % 16], 1);
		ft_putstr(" ");
		i++;
	}
	ft_adjust_output(buffer, 0, (16 - max) * 3 + (max < 8 ? 1 : 0));
	ft_putstr(" |");
	i = 0;
	while (i < max)
	{
		write(1, &buffer[i], 1);
		i++;
	}
	ft_putstr("|\n");
}

void	ft_print_without_flag(char *buffer, int print, int i, int max)
{
	ft_print_address(print, print, 0, 6);
	while (i < max)
	{
		ft_putstr(" ");
		write(1, &"0123456789abcdef"[buffer[i + 1] / 16], 1);
		write(1, &"0123456789abcdef"[buffer[i + 1] % 16], 1);
		write(1, &"0123456789abcdef"[buffer[i] / 16], 1);
		write(1, &"0123456789abcdef"[buffer[i] % 16], 1);
		i += 2;
	}
	ft_putstr("\n");
}

void	ft_last(t_reader *actual, int flag, char *buffer)
{
	if (actual->i != 0)
	{
		if (flag)
			ft_print_with_flag(buffer, actual->print * 16, 0, actual->i);
		else
			ft_print_without_flag(buffer, actual->print * 16, 0, actual->i);
		ft_print_address(actual->print * 16 + actual->i, 
		actual->print * 16 + actual->i, 0, flag ? 7 : 6);
	}
}
