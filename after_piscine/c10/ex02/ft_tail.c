#include "ft_tail.h"

int		ft_tail(int argc, char **argv, int i, int bytes)
{
	if (i < argc)
	{
		if (!ft_strcmp(argv[i], "-c"))
			return (ft_tail(argc, argv, i + 2, bytes));
		if ((ft_display_file(argc, argv, i, bytes)) == -1)
			ft_error(argv[i], basename(argv[0]), strerror(errno));
		return (ft_tail(argc, argv, i + 1, bytes));
	}
	return (0);
}

void	ft_stdin_read(void)
{
	char	c;
	int		reader;

	while ((reader = read(0, &c, 1)));
}

int		main(int argc, char **argv)
{
	int		bytes;

	bytes = ft_check_flag(argc, argv);
	if (argc < 3)
		return (1);
	else if (bytes == -1)
		return (ft_bytes_error(argc, argv, basename(argv[0])));
	else if (argc == 3)
		ft_stdin_read();
	else
		ft_tail(argc, argv, 1, bytes);
	return (0);
}
