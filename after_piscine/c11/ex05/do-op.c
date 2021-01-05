#include "do-op.h"

int	do_op(int f, int s, char operator, char *operators)
{
	int	i;
	int		(*operations[5])(int, int) = {&ft_add, &ft_minus, &ft_multiply, &ft_divide, &ft_modulo}; 

	i = 0;
	while (i < 5)
	{
		if (operator == operators[i])
			return (operations[i](f, s));
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		result;
	char	operators[5] = {'+', '-', '*', '/', '%'};
	
	if (argc != 4)
		return (-1);
	if (!ft_check(argv[2], operators, ft_atoi(argv[3])))
		return (-1);
	result = do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2][0], operators);
	ft_putnbr(result);
	ft_putstr("\n");
	return (0);
}
