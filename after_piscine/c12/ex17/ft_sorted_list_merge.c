#include "ft_list.h"

void    ft_list_merge(t_list *begin_list1, t_list *begin_list2)
{
    t_list  *current;

    current = begin_list1;
    if (!current)
        return ;
    while (current->next)
        current = current->next;
    current->next = begin_list2;
}

void    ft_sorted_list_merge(t_list **begin_list1, t_list **begin_list2, int (*cmp)())
{
    t_list  *cursor;
	t_list	*tmp;

    cursor = *begin_list1;
    while (cursor->next && *begin_list2)
    {
		if (cmp(cursor->data, (*begin_list2)->data) >= 0)
		{
			tmp = *begin_list2;
			*begin_list2 = (*begin_list2)->next;
			tmp->next = *begin_list1;
			*begin_list1 = tmp;
			cursor = *begin_list1;
		}
		else if (cmp(cursor->next->data, (*begin_list2)->data) >= 0)
		{
			tmp = *begin_list2;
			*begin_list2 = (*begin_list2)->next;
			tmp->next = cursor->next;
			cursor->next = tmp;
		}
		else
			cursor = cursor->next;
    }
	if (cursor)
		ft_list_merge(*begin_list1, *begin_list2);
}
