s#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

int		main(void)
{
	char first[3] = {'a', 'b', 'c'};
	char second[3] = {'d', 'e', 'f'};

	ft_memcpy(first, second, sizeof(second));
	for (int i = 0; i < 3; i++)
		printf("%c\n", first[i]);
	return (0);
}
