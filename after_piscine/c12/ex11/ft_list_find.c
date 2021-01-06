#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cursor;

	cursor = begin_list;
	while (cursor)
	{
		if (!cmp(cursor->data, data_ref))
			return (cursor);
		cursor = cursor->next;
	}
	return (cursor);
}
