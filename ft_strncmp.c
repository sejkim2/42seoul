#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t i;
	unsigned char *p1;
	unsigned char *p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (p1 == 0 && p2 == 0)
		return (0);
	while (i < n && (p1[i] || p2[i]))
	{
		if (p1[i] == p2[i])
			i++;
		else
			return (p1[i] - p2[i]);
	}
	return (0);
}