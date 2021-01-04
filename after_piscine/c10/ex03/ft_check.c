#include "ft_hexdump.h"

int		ft_check_flag(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-C"))
			return (true);
		i++;
	}
	return (false);
}
