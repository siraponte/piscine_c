#include "ft_hexdump.h"

t_reader	*ft_read_file(int file, int flag, char *buffer, t_reader *actual)
{
	int		reader;
	char	c;

	while ((reader = read(file, &c, 1)))
	{
		if (reader == -1)
		{
			actual->i = -1;
			return (actual);
		}
		if (actual->i == 16)
		{
			actual->i = 0;
			if (flag)
				ft_print_with_flag(buffer, actual->print * 16, 0, 16);
			else
				ft_print_without_flag(buffer, actual->print * 16, 0, 16);
			actual->print++;
		}
		buffer[actual->i] = c;
		actual->i++;
	}
	return (actual);
}

int		ft_open_file(char **argv, int i)
{
	int		file;
	
	if (!ft_strcmp(argv[i], "-C"))
		return (-1);
	if ((file = open(argv[i], O_RDONLY)) == -1)
		return (ft_error(basename(argv[0]), argv[i], strerror(errno)));
	return (file);
}

void	ft_hexdump(int flag, char *buffer, int argc, char **argv)
{
	int			file;
	int			i;
	t_reader	*actual;

	i = 1;
	if (!(actual = malloc(sizeof(t_reader *))))
		return ;
	actual->print = 0;
	actual->i = 0;
	while (i < argc)
	{
		if ((file = ft_open_file(argv, i)) == -1)
		{
			i++;
			continue ;
		}
		actual = ft_read_file(file, flag, buffer, actual);
		if (actual->i == -1)
			ft_error(basename(argv[0]), argv[i], strerror(errno));
		i++;
		close(file);
	}
	if (actual->i != 0)
		ft_last(actual, flag, buffer);
	if ((argc == 2 && !flag && open(argv[1], O_RDONLY) == -1) ||
	(argc == 3 && flag && ((open(argv[1], O_RDONLY) == -1) || open(argv[2], O_RDONLY) == -1)));
	else
		ft_putstr("\n");
}

void	ft_read_stdin(int flag, char *buffer, int i, int print)
{
	int		reader;
	char	c;

	while ((reader = read(0, &c, 1)))
	{
		if (i == 16)
		{
			i = 0;
			if (flag)
				ft_print_with_flag(buffer, print * 16, 0, 16);
			else
				ft_print_without_flag(buffer, print * 16, 0, 16);
			print++;
		}
		buffer[i] = c;
		i++;
	}
}

int		main(int argc, char **argv)
{
	int flag;
	char *buffer;

	if(!(buffer = malloc(16 * sizeof(char))))
		return (1);
	flag = ft_check_flag(argc, argv);
	if (argc == 1)
		ft_read_stdin(flag, buffer, 0, 0);
	else if (argc == 2 && flag)
		ft_read_stdin(flag, buffer, 0, 0);
	else if (flag)
		ft_hexdump(flag, buffer, argc, argv);
	else
		ft_hexdump(flag, buffer, argc, argv);
	free(buffer);
}
