#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*actual;

	actual = begin_list;
	while (actual && nbr)
	{
		actual = actual->next;
		nbr--;
	}
	return (actual);
}
