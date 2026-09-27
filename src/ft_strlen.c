#include "../include/libft.h"
#include <stddef.h>

size_t  ft_strlen(const char *s)
{
    size_t  res;

    res = 0;
    while (s[res])
        res++;
    return (res);
}
