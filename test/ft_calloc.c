#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <strings.h>
#include "../include/libft.h"

void    __real_ft_bzero(void *s, size_t size);
void    *__real_malloc(size_t size);
bool    should_malloc_fail = false;

void    *__wrap_malloc(size_t size)
{
    if (should_malloc_fail)
        return (NULL);
    else
        return (malloc(size));
}

void    __wrap_ft_bzero(void *s, size_t size)
{
    bzero(s, size);
}

void    setup(void)
{
    should_malloc_fail = false;
}

Test(ft_calloc, func_return_null_if_malloc_fail, .init=setup)
{
    char    *test;

    should_malloc_fail = true;
    test = ft_calloc(42, 2);
    cr_assert_eq(test, NULL);
}

Test(ft_calloc, func_return_null_if_n_0, .init=setup)
{
    char    *test;

    test = ft_calloc(0, 4);
    cr_assert_eq(test, NULL);
}

Test(ft_calloc, func_return_null_if_size_0, .init=setup)
{
    char    *test;

    test = ft_calloc(42, 0);
    cr_assert_eq(test, NULL);
}

Test(ft_calloc, func_return_char_array_full_0, .init=setup)
{
    char    *test;

    test = ft_calloc(50, 1);
    for (int i = 0; i < 50; i++) {
        cr_assert_eq(test[i], 0);
    }
}

Test(ft_calloc, func_return_int_array_full_0, .init=setup)
{
    int *test;

    test = ft_calloc(50, 4);
    for (int i = 0; i < (50 * 4); i++) {
        cr_assert_eq(test[i], 0);
    }
}
