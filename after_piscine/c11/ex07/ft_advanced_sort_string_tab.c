void	ft_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if ((cmp(tab[i], tab[j])) > 0)
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
