#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>

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

Test(ft_substr, null_if_len_is_zero, .init=setup)
{
    char    *res;

    res = ft_substr("bien le bonjour", 0, 0);
    cr_assert_eq(strcmp("", res), 0);
}

Test(ft_substr, return_substring_0, .init=setup)
{
    char    *res;
    char    *test = "bien";

    res = ft_substr("bien le bonjour", 0, 4);
    cr_assert_eq(strcmp(test, res), 0);
}

Test(ft_substr, return_substring_1, .init=setup)
{
    char    *res;
    char    *test = "Remuneree";

    res = ft_substr("Stage Non Remuneree les batards", 10, 9);
    cr_assert_eq(strcmp(res, test), 0);
}

Test(ft_substr, return_substring_2, .init=setup)
{
    char    *res;
    char    *test = "clermont";

    res = ft_substr("Boussif de clermont-ferant", 11, 8);
    cr_assert_eq(strcmp(res, test), 0);
}

Test(ft_substr, return_rest_of_string_if_len_gt_string, .init=setup)
{
    char    *res;
    char    *test = "passer le correcteur";

    res = ft_substr("Non, je n'ai pas envie de passer le correcteur", 26, 500);
    cr_assert_eq(strcmp(res, test), 0);
}

Test(ft_substr, return_rest_of_string_if_len_lt_0, .init=setup)
{
    char    *res;
    char    *test = "passer le correcteur";

    res = ft_substr("Non, je n'ai pas envie de passer le correcteur", 26, -500);
    cr_assert_eq(strcmp(res, test), 0);
}


Test(ft_substr, return_null_ptr_malloc_fail, .init=setup)
{
    char    *res;

    should_malloc_fail = true;
    res = ft_substr("belle bite shinji", 10, 43);
    cr_assert_eq(NULL, res);
}

Test(ft_substr, should_segfault_if_given_a_null, .signal=11, .init=setup)
{
    ft_substr(NULL, 0, 12);
}
