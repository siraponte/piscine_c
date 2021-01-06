#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*cursor;

	if(!(new = ft_create_elem(data)))
		return ;
	new->data = data;
	new->next = NULL;
	cursor = *begin_list;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new;
	cursor = NULL;
}
