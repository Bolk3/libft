#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <ctype.h>
#include "../include/libft.h"

void    test_func(unsigned int i, char *s)
{
    s[i] = toupper(s[i]);
}

void    test_func_1(unsigned int i, char *s)
{
    s[i] = (s[i] + i) % 128;
}

Test(ft_striteri, segfault_if_null_ptr, .signal=11)
{
    char    *test = NULL;
    ft_striteri(test, test_func);
}

Test(ft_striteri, string_return_test_0)
{
    char    *res = "Bonjour;;Bonjour";
    char    *test = "BONJOUR;;BONJOUR";

    ft_striteri(res, test_func);
    cr_assert_str_eq(res , test);
}

Test(ft_striteri, void_string_return_void)
{
    char    *res = "";

    ft_striteri(res, test_func);
    cr_assert_str_empty(res);
}

Test(ft_striteri, string_return_test_1)
{
    char    *res = "on s'enuit";
    char    *test = "on s'enuit";

    for (int i = 0; test[i]; i++)
        test_func_1(i, test);
    ft_striteri(test, test_func_1);
    cr_assert_str_eq(test, res);
}
