#include "ft_tail.h"

void	ft_put_header(int argc, char **argv, int i)
{
	if (argc > 4)
	{
		ft_putstr("==> ");
		ft_putstr(basename(argv[i]));
		ft_putstr(" <==");
		ft_putstr("\n");
	}
}

int		ft_print(int file, int new_char)
{
	int		reader;
	int		chars;
	char	c;

	chars = 0;
	while ((reader = read(file, &c, 1)))
	{
		if (reader == -1)
			return (-1);
		if (chars >= new_char)
			write(1, &c, 1);
		chars++;
	}
	return (0);
}

int		ft_display_file(int argc, char **argv, int i, int bytes)
{
	int		file;
	int		new_char;

	if ((file = open(argv[i], O_RDONLY)) == -1)
		return (-1);
	if ((new_char = ft_char_count(argv, bytes, i)) == -1)
		return (-1);
	ft_put_header(argc, argv, i);
	if (ft_print(file, new_char) == -1)
		return (-1);
	if (i + 1 < argc)
	{
			if (open(argv[i + 1], O_RDONLY) != -1
			|| (!ft_strcmp(argv[i + 1], "-c") && i + 3 != argc))
			ft_putstr("\n");
	}
	close(file);
	return (0);
}
