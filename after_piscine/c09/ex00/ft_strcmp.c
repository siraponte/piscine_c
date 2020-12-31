int	ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - s2[i]);
}
