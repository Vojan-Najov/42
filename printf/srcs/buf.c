#include "printf.h"
#include <string.h>
#include <stdio.h>

static char *buf;
static char *ptr;
static int  bufsize;

char    *buf_init()
{
    bufsize = 2 * 1024;
    buf = (char *)malloc(sizeof(*buf) * bufsize);
    ptr = buf;
    return (buf);
}

char    *ft_realloc(void *mptr, size_t size, size_t memsize)
{
    char    *ret;

    ret = malloc(size);
    if (ret)
        memcpy(ret, mptr, memsize);
    free(mptr);
    return (ret);
}

char    *buf_realloc()
{
    size_t  n;

    n = ptr - buf;
    bufsize += 2 * 1024;
    buf = ft_realloc(buf, bufsize, n);
    ptr = buf + n;
    return (buf);
}

char    *buf_add(const char *str, unsigned int k)
{
    if (ptr + k > buf + bufsize)
        buf_realloc();
    if (!buf)
        return (NULL);
    while (k-- > 0)
        *ptr++ = *str++;
    return (ptr);
}

int     buf_output()
{
    size_t  n;

    if (!buf)
        return (-1);
    n = ptr - buf;
    write(1, buf, n);
    free(buf);
    buf = NULL;
    return ((int) n);
}

////////////////////////////////////////////////////////////

char    *buf_add_fmt(const char *fmt, va_list *ap)
{
    (void) ap;
    if (*fmt == '%')
        return (buf_add(fmt, 1));
    else if (*fmt == 'c')
    {
        char    c;
        
        c = va_arg(*ap, int);
        return (buf_add(&c, 1));
    }
    else if (*fmt == 's')
    {
        char    *s;
        
        s = va_arg(*ap, char *);
        return (buf_add(s, strlen(s)));
    }
    else if (*fmt == 'd' || *fmt == 'i')
    {
        char    *s;
        int     d;
        char    *p;

        d = va_arg(*ap, int);
        s = ft_itoa(d);
        p = buf_add(s, strlen(s));
        free(s);
        return (p);
    }
    else if (*fmt == 'u')
    {
        char        *s;
        unsigned    n;
        char        *p;

        n = va_arg(*ap, unsigned);
        s = ft_utoa_base(n, 10);
        p = buf_add(s, strlen(s));
        free(s);
        return (p);
    }   
    else if (*fmt == 'x')
    {
        char        *s;
        unsigned    n;
        char        *p;

        n = va_arg(*ap, unsigned);
        s = ft_utoa_base(n, 16);
        p = buf_add(s, strlen(s));
        free(s);
        return (p);
    }
    else if (*fmt == 'X')
    {
        char        *s;
        unsigned    n;
        char        *p;

        n = va_arg(*ap, unsigned);
        s = ft_utoa_base(n, 16);
        p = s;
        while (*p)
        {
            *p = ft_toupper(*p);
            ++p;
        }
        p = buf_add(s, strlen(s));
        free(s);
        return (p);
    }
    else if (*fmt == 'p')
    {
        char            *s;
        unsigned long    n;
        char            *p;

        n = va_arg(*ap, unsigned long);
        s = ft_ultoa_base(n, 16);
        p = buf_add("0x", 2);
        if (!p)
            return (NULL);
        p = buf_add(s, strlen(s));
        free(s);
        return (p);
    }

    else
        return (NULL);
}

///////////////////////////////////////////////////////////

int ft_printf(const char *fmt, ...)
{
    va_list ap;

    if (!fmt)
    {
        ft_printf("null\n");
        return (-1);
    }
    if (buf_init() == NULL)
        return (-1);
    va_start(ap, fmt);
    while (*fmt)
    {
        if (*fmt != '%')
        {
            if (buf_add(fmt, 1) == NULL)
                return (-1);
        }
        else
            if (buf_add_fmt(++fmt, &ap) == NULL)
                return (-1);
        ++fmt;
    }
    va_end(ap);
    return (buf_output());
}

///////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_printf(argv[1]);
        ft_printf("\n");
    }
    else if (argc == 1)
    {
        ft_printf("hello %c 123\n", 'D');
        ft_printf("hello %s 123\n", "BOB");
        ft_printf("hello %c 1 %s 2 %d 3 %i 4\n", 'D', "BOB", 192, -1212);
        ft_printf("hell %u gg\n", 221232323);
        ft_printf("hel %x ooo %X ooo\n", 4877, 3478347);
        printf("hel %x ooo %X ooo\n", 4877, 3478347);
        printf("%lu\n", sizeof(void *));

        char *s;
        s = malloc(1);
        ft_printf("%p\n", s);
        printf("%p\n", s);
        free (s);
    }
    else
        ft_printf(NULL);
    //printf("\n");
    return (0);
}
