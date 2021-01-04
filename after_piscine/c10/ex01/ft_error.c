#include "ft_cat.h"

void	ft_error(char *arg, char *program, char *error)
{
	ft_putstr(program);
	ft_putstr(": ");
	ft_putstr(arg);
	ft_putstr(": ");
	ft_putstr(error);
	ft_putstr("\n");
}
