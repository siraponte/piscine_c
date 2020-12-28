#include "ft_stock_str.h"
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		count;

	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (0);
	count = 0;
	while (src[count] != '\0')
	{
		str[count] = src[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

struct s_stock_str  *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str     *ptr;
    int             index;
    
    index = 0;
    ptr = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
    if (!ptr)
        return (0);
    while (index < ac)
    {
        ptr[index].size = ft_strlen(av[index]);
        ptr[index].str = av[index];
        ptr[index].copy = ft_strdup(av[index]);
        index++;
    }
    ptr[index].str = 0;
    return (ptr);
}