#include "do-op.h"

bool	ft_error(char operator)
{
	if (operator == '/')
		ft_putstr("Stop : division by zero\n");		
	else if (operator == '%')
		ft_putstr("Stop : modulo by zero\n");
	return(false);
}
