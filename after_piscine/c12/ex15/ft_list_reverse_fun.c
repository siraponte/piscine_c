#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int     n;
    t_list  *cursor;

    n = 0;
    cursor = begin_list;
    while (cursor)
    {
        cursor = cursor->next;
        n++;
    }
    return (n);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		size;
	int		fake;
	t_list	*cursor;
	t_list	*reverse_cursor;
	void	*tmp;

	i = 0;
	size = ft_list_size(begin_list);
	cursor = begin_list;
	while (i < size / 2)
	{
		fake = size - i;
		reverse_cursor = begin_list;
		while (--fake)
			reverse_cursor = reverse_cursor->next;
		tmp = cursor->data;
		cursor->data = reverse_cursor->data;
		reverse_cursor->data = tmp;
		cursor = cursor->next;
		i++;
	}
}
