#include "../include/libft.h"
#include <stddef.h>

void    *ft_memset(void *a, int c, size_t n)
{
    size_t  i;
    char    *cpy;

    i = 0;
    cpy = (char *)a;
    while (i++ < n)
        cpy[i] = c;
    return(a);
}
