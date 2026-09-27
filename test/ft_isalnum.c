#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <limits.h>
#include "../include/libft.h"

Test(isalnum, is_all_alpha_valid)
{
    for (int c = 'a'; c <= 'z'; c++) {
        cr_assert(ft_isalnum(c) != 0);
    }
    for (int c = 'A'; c <= 'Z'; c++) {
        cr_assert(ft_isalnum(c) != 0);
    }
}

Test(isalnum, is_all_number_valid)
{
    for (int c = '0'; c <= '9'; c++) {
        cr_assert(ft_isalnum(c) != 0);
    }
}

Test(isalnum, is_all_other_invalid)
{
    for (int c = 0; c < '0'; c++) {
        cr_assert(ft_isalnum(c) == 0);
    }
    for (int c = '9' + 1; c < 'A'; c++) {
        cr_assert(ft_isalnum(c) == 0);
    }
    for (int c = 'Z' + 1; c < 'a'; c++) {
        cr_assert(ft_isalnum(c) == 0);
    }
    for (int c = 'z' + 1; c <= 127; c++) {
        cr_assert(ft_isalnum(c) == 0);
    }
}
