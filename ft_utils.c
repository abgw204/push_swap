#include "stack.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*ptr;
	size_t			total_size;
	size_t			i;
	unsigned char	*str;

	i = 0;
	if (num != 0 && (num * size) / num != size)
		return (NULL);
	total_size = num * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	str = (unsigned char *)ptr;
	while (i < total_size)
		str[i++] = '\0';
	return (ptr);
}