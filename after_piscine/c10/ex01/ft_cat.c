#include "ft_cat.h"

void	ft_cat(int argc, char **argv, int i)
{
	int		file;
	int		reader;
	char	c;

	if (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1)
		{
			ft_error(argv[i], basename(argv[0]), strerror(errno));
			return ;
		}
		while ((reader = read(file, &c, 1)))
		{
			if (reader == -1)
			{
				ft_error(argv[i], basename(argv[0]), strerror(errno));
				return ;
			}
			write(1, &c, 1);
		}
		ft_cat(argc, argv, i + 1);
	}
}

void	ft_stdin_read(char *program)
{
	char	c;
	int		reader;

	while ((reader = read(0, &c, 1)))
	{
		if (reader == -1)
		{
			ft_error(0, program, strerror(errno));
			return ;
		}
		write (1, &c, 1);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_stdin_read(basename(argv[0]));
	else
		ft_cat(argc, argv, 1);
}
