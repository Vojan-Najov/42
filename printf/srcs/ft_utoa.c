#include "printf.h"

static char dgts[] = {'0', '1', '2', '3', '4', '5', \
                        '6', '7', '8', '9', 'a', 'b', \
                        'c', 'd', 'e', 'f'};

static unsigned ft_count_digits(unsigned n, unsigned base);

char    *ft_utoa_base(unsigned n, unsigned base)
{
    unsigned    size;
    unsigned    rem;
    char        *str;
    
    size = ft_count_digits(n, base);
    str = (char *) malloc(sizeof(*str) * (size + 1));
    if (!str)
        return (NULL);
    str[size] = '\0';
    if (n == 0)
        str[0] = dgts[0];
    while (n)
    {
        rem = n % base;
        str[--size] = dgts[rem];
        n /= base;
    }
    return (str);
}

static unsigned ft_count_digits(unsigned n, unsigned base)
{
    unsigned    count;

    count = 0;
    if (n == 0)
        ++count;
    while (n)
    {
        ++count;
        n /= base;
    }
    return (count);
}
