#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	t_list	*cursor;

	if (!(new = ft_create_elem(data)))
		return ;
	cursor = *begin_list;
	while (cursor)
	{
		if (cmp(cursor->data, new->data) >= 0)
		{
			new->next = cursor;
			*begin_list = new;
			break ;
		}
		if (!cursor->next || cmp(cursor->next->data, new->data) >= 0)
		{
			new->next = cursor->next;
			cursor->next = new;
			break ;
		}
		cursor = cursor->next;
	}
}
