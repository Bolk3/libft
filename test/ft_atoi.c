#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdint.h>
#include <wchar.h>

Test(ft_atoi, more_than_one_sign_equals_zero)
{
    cr_assert_eq(ft_atoi("--42"), 0);
    cr_assert_eq(ft_atoi("+-42"), 0);
    cr_assert_eq(ft_atoi("++42"), 0);
}

Test(ft_atoi, return_max_int)
{
    cr_assert_eq(ft_atoi("2147483647"), 2147483647);
}

Test(ft_atoi, return_min_int)
{
    cr_assert_eq(ft_atoi("-2147483647"), -2147483647);
}

Test(ft_atoi, return_first_part_of_string)
{
    cr_assert_eq(ft_atoi("42quarante_deux"), 42);
}

Test(ft_atoi, null_pointer_should_segfault, .signal=11)
{
    ft_atoi(NULL);
}
