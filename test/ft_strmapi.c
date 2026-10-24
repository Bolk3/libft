#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <wchar.h>

bool    should_malloc_fail = false;

void    *__real_malloc(size_t size);
void    *__warp_malloc(size_t size)
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

char    test_func_0(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (toupper(c));
    return (tolower(c));
}

char    test_func_1(unsigned int i, char c)
{
    (void) i;
    return(toupper(c));
}

TestSuite(ft_strmapi, .init=setup);
Test(ft_strmapi, return_null_malloc_fail)
{
    char    *res;

    should_malloc_fail = true;
    res = ft_strmapi("omdedeto shinji", test_func_0);
    cr_assert_null(res);
}

Test(ft_strmapi, segfault_if_null_ptr, .signal=11)
{
    char    *res;

    res = ft_strmapi(NULL, test_func_0);
}

Test(ft_strmapi, return_string_through_test_0)
{
    char    *res;
    char    *test = "Test Test Test";

    for (int i = 0; test[i]; i++)
        test[i] = test_func_0(i, test[i]);
    res = ft_strmapi("Test Test Test", test_func_0);
    cr_assert_str_eq(res, test);
}

Test(ft_strmapi, return_string_through_test_1)
{
    char    *res;
    char    *test = "Bonjour Bonjour";

    for (int i = 0; test[i]; i++)
        test[i] = test_func_1(i, test[i]);
    res = ft_strmapi("Bonjour Bonjour", test_func_1);
    cr_assert_str_eq(test, res);
}
