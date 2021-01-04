#include "ft_hexdump.h"

int		ft_error(char *program, char *arg, char *error)
{
    ft_putstr(program);
    ft_putstr(": ");
    ft_putstr(arg);
    ft_putstr(": ");
    ft_putstr(error);
	ft_putstr("\n");
	return (-1);
}
