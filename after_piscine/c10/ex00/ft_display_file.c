#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		file;
	char	c;
	ssize_t	reading;

	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else if ((file = open(argv[1], O_RDONLY)) == -1) 
		write(1, "Cannot read file.\n", 19);
	else if ((reading = read(file, &c, 1)) != -1)
	{
		while (reading)
		{
			write(1, &c, 1);
			reading = read(file, &c, 1);
		}
		return (0);
	}
	return (1);
}
