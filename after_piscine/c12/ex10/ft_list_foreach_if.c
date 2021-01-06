#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*cursor;

	cursor = begin_list;
	while (cursor)
	{
		if (!cmp(cursor->data, data_ref))
			f(cursor->data);
		cursor = cursor->next;
	}
}
