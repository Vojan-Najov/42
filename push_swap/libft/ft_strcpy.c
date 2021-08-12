#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*d;

	d = dst;
	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dst);
}
