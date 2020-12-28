#include <stdlib.h>
#include <stdbool.h>

int		g_nbr;

char	*ft_strncpy(char *dest, char *src, unsigned int n, int index)
{
	while (src[index] && index < n)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		is_in_charset(char *charset, char to_find, int index)
{
	while (charset[index])
	{
		if (to_find == charset[index])
			return (true);
		index++;
	}
	return (false);
}

char	*ft_find_next(char **actual, int *str_len, char *charset, int index)
{
	char	*str_start;

	*str_len = 0;
	str_start = 0;
	while (actual[0][index])
	{
		if (is_in_charset(charset, actual[0][index], 0) && str_start != 0)
		{
			actual[0] = str_start + *str_len;
			return (str_start);
		}
		else if (!is_in_charset(charset, actual[0][index], 0) && str_start == 0)
			str_start = &actual[0][index];
		if (!is_in_charset(charset, actual[0][index], 0))
			*str_len += 1;
		index++;
	}
	actual[0] = str_start + *str_len;
	if (*str_len == 0)
		return (0);
	return (str_start);
}

char	**ft_split(char *str, char *charset)
{
	char	**matrix;
	char	*next;
	char	*actual;
	int		index;
	int		str_len;

	actual = str;
	g_nbr = 0;
	while (ft_find_next(&actual, &str_len, charset, 0))
		g_nbr++;
	if (!(matrix = (char **)malloc((g_nbr + 1) * sizeof(char *))))
		return (0);
	index = 0;
	actual = str;
	while ((next = ft_find_next(&actual, &str_len, charset, 0)))
	{
		if (!(matrix[index] = (char *)malloc((str_len + 1) * sizeof(char))))
			return (0);
		ft_strncpy(matrix[index++], next, str_len, 0);
	}
	matrix[index] = 0;
	return (matrix);
}