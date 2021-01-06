#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*cursor;

	cursor = begin_list;
	while (cursor)
	{
		f(cursor->data);
		cursor = cursor->next;
	}
}
