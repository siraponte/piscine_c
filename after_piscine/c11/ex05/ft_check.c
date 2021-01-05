#include "do-op.h"

bool	ft_check(char *operator, char *operators, int value2)
{
	int	i;

	i = 0;
	if (ft_strlen(operator) == 1)
	{
		while (i < 5)
		{
			if (operator[0] == operators[i])
			{
				if (value2 == 0 && (i == 3 || i == 4))
					return (ft_error(operator[0]));
				return (true);
			}
			i++;
		}
	}
	return (false);
}
