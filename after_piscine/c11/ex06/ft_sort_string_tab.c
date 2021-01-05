#include <stdbool.h>

bool    ft_strcmp(char *s1, char *s2)
{
    int result;
    int i;

    i = 0;
    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0')
            break ;
        i++;
    }
    result = (unsigned char)s1[i] - s2[i];
    if (result > 0)
        return (true);
    return (false);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i + 1][0] != '\0')
	{
		j = i + 1;
		while (tab[j][0] != '\0')
		{
			if (ft_strcmp(tab[i], tab[j]))
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}

}
