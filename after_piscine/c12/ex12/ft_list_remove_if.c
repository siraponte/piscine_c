#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*actual;
	t_list	*next;
	t_list	*previous;

	actual = *begin_list;
	while (actual)
	{
		next = actual->next;
		if (!cmp(actual->data, data_ref))
		{
			if (actual == *begin_list)
				*begin_list = next;
			else
				previous->next = next;
			free_fct(actual->data);
			free(actual);
		}
		else
			previous = actual;
		actual = next;
	}
}
