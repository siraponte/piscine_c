#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		n;
	t_list	*cursor;

	n = 0;
	cursor = begin_list;
	while (cursor)
	{
		cursor = cursor->next;
		n++;
	}
	return (n);
}
