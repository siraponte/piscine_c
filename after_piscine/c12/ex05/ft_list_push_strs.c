#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*new;

	if (size == 0)
		return (NULL);
	new = ft_create_elem(strs[size - 1]);
	new->next = ft_list_push_strs(size - 1, strs);
	return (new);
}
