#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		swap;
	t_list	*current;
	t_list	*tmp;

	swap = 0;
	current = *begin_list;
	if (!current)
		return ;
	while (current->next)
	{
		if (cmp(current->data, current->next->data) > 0)
		{
			tmp = current->next;
			current->next = current;
			current = tmp;
			swap++;
		}
		current = current->next;
	}
	if (swap)
		ft_list_sort(begin_list, cmp);
}
