#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	if (!(new = ft_create_elem(data)))
		return ;
	new->next = (*begin_list);
	*begin_list = new;
}
