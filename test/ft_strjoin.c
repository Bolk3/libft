#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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

TestSuite(ft_strjoin, .init=setup);
Test(ft_strjoin, should_segfault_if_s1_null, .signal=11)
{
    ft_strjoin(NULL, "test");
}

Test(ft_strjoin, should_segfault_if_s2_null, .signal=11)
{
    ft_strjoin("test", NULL);
}

Test(ft_strjoin, should_return_null_if_malloc_fail)
{
    char    *res;

    should_malloc_fail = true;
    res = ft_strjoin("test", "test");
    cr_assert_null(res);
}

Test(ft_strjoin, return_concat_of_string_0)
{
    char    *res;
    char    *s1 = "Michel ";
    char    *s2 = "Sardou";

    res = ft_strjoin(s1, s2);
    cr_assert_str_eq(res, "Michel Sardou");
}

Test(ft_strjoin, return_concat_of_string_1)
{
    char    *res;
    char    *s1 = "de quoi tu parle fdp";
    char    *s2 = " putain de merde";

    res = ft_strjoin(s1, s2);
    cr_assert_str_eq(res, "de quoi tu parle fdp putain de merde");
}

Test(ft_strjoin, empty_s1_return_s2)
{
    char    *res;
    char    *s1 = "";
    char    *s2 = "tien tien tien";

    res = ft_strjoin(s1, s2);
    cr_assert_str_eq(res, s2);
}

Test(ft_strjoin, empty_s2_return_s1)
{
    char    *res;
    char    *s1 = "well well well";
    char    *s2 = "";

    res = ft_strjoin(s1, s2);
    cr_assert_str_eq(res, s1);
}
