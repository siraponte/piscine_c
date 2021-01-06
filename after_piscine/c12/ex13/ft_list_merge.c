#include "ft_list.h"

void	ft_list_merge(t_list *begin_list1, t_list *begin_list2)
{
	t_list	*current;

	current = begin_list1;
	if (!current)
		return ;
	while (current->next)
		current = current->next;
	current->next = begin_list2;
}
