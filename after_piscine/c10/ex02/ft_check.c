#include "ft_tail.h"

int		ft_char_count(char **argv, int bytes, int i)
{
	char	c;
	int		file;
	int		reader;
	int		new_char;

	new_char = 0;
	if ((file = open(argv[i], O_RDONLY)) == -1)
	{
		ft_error(argv[i], basename(argv[0]), strerror(errno));
		return (-1);
	}
	while ((reader = read(file, &c, 1)))
	{
		if (reader == -1)
		{
			ft_error(argv[i], basename(argv[0]), strerror(errno));
			return (-1);
		}
		new_char++;
	}
	close(file);
	return (new_char - bytes > 0 ? new_char - bytes : 0);
}

int		ft_check_flag(int argc, char **argv)
{
	int	i;
	int	bytes;

	i = 1;
    while (i < argc)
    {
        if (!ft_strcmp(argv[i], "-c") && i < argc - 1)
        {
            if (ft_str_is_numeric(argv[i + 1]))
            {
				bytes = ft_atoi(argv[i + 1]);
                return (ABS(bytes));
            }
        }
        i++;
    }
    return (-1);
}
