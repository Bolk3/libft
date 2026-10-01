#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>

size_t  __real_ft_strlen(const char *s);
void    *__real_malloc(size_t size);
bool    should_malloc_fail = false;

size_t  __wrap_ft_strlen(const char *s)
{
    return (strlen(s));
}

void    *__wrap_malloc(size_t size)
{
    if (should_malloc_fail)
        return (NULL);
    else
        return (__real_malloc(size));
}

void    setup(void)
{
    should_malloc_fail = false;
}

Test(ft_strdup, func_return_null_if_not_malloc, .init=setup)
{
    char    *test = "test test";
    char    *res;

    should_malloc_fail = true;
    res = ft_strdup(test);
    cr_assert_eq(res, NULL);
}

Test(ft_strdup, func_return_dup, .init=setup)
{
    char    *test = "test test";
    char    *res;

    res = ft_strdup(test);
    for (int i = 0; test[i]; i++) {
        cr_assert_eq(res[i], test[i]);
    }
}
