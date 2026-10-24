#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

bool    should_malloc_fail = false;

void    *__real_malloc(size_t size);
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

TestSuite(ft_itoa, .init=setup);

Test(ft_itoa, return_null_if_malloc_fail)
{
    char    *res;

    should_malloc_fail = true;
    res = ft_itoa(42);
    cr_assert_null(res);
}

Test(ft_itoa, return_neg_number_string_0)
{
    char    *res;

    res = ft_itoa(-42);
    cr_assert_str_eq(res, "-42");
}

Test(ft_itoa, return_neg_number_string_1)
{
    char    *res;

    res = ft_itoa(-234);
    cr_assert_str_eq(res, "-234");
}

Test(ft_itoa, return_neg_number_string_2)
{
    char    *res;

    res = ft_itoa(-5673);
    cr_assert_str_eq(res, "-5673");
}

Test(ft_itoa, return_number_string)
{
    char    *res;

    res = ft_itoa(42);
    cr_assert_str_eq(res, "42");
}

Test(ft_itoa, return_zero_string)
{
    cr_assert_str_eq(ft_itoa(0), "0");
}
