#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *returnn;
	int	i;

	if(!(returnn = (int *)malloc(length * sizeof(int))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		returnn[i] = f(tab[i]);
		i++;
	}
	return (returnn);
}
