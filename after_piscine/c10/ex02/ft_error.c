#include "ft_tail.h"

int		ft_error(char *arg, char *program, char *error)
{
	ft_putstr(program);
	ft_putstr(": ");
	ft_putstr("cannot open '");
	ft_putstr(arg);
	ft_putstr("' for reading: ");
	ft_putstr(error);
	ft_putstr("\n");
	return (1);
}

int		ft_bytes_error(int argc, char **argv, char *program)
{
	int i;

	i = 1;
	ft_putstr(program);
	ft_putstr(": invalid number of bytes: '");
	while (i < argc && ft_strcmp(argv[i], "-c"))
		i++;
	ft_putstr(argv[i + 1]);
	ft_putstr("'");
	ft_putstr("\n");
	return (1);
}
