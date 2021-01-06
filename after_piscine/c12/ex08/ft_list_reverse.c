#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*actual;
	t_list	*next;
	t_list	*previous;

	previous = NULL;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}
