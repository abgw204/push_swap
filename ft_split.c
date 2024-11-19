#include "stack.h"

static size_t	count_words(char const *s, char c)
{
	int	i;
	int	counter;
	int	flag;

	i = 0;
	counter = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (counter);
}

static size_t	find_size(char const *str, char c, int *index)
{
	size_t	size;
	size_t	flag;

	size = 0;
	flag = 0;
	while (str[*index])
	{
		if (str[*index] != c && str[*index])
		{
			size++;
			flag = 1;
		}
		else if (str[*index] == c && flag == 1)
			return (size);
		(*index)++;
	}
	return (size);
}

static void	transform(char **array, char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	pos;

	i = 0;
	k = 0;
	pos = 0;
	while (s[pos])
	{
		while (s[pos] == c)
			pos++;
		while (s[pos] && s[pos] != c)
			array[i][k++] = s[pos++];
		k = 0;
		i++;
	}
}

static char	**verify(char **array, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**array;
	size_t		i;
	size_t		size;
	int			index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < count_words(s, c))
	{
		size = find_size(s, c, &index);
		array[i] = (char *)calloc(size + 1, 1);
		if (!array[i])
			return (verify(array, i));
		i++;
	}
	transform(array, s, c);
	array[i] = NULL;
	return (array);
}