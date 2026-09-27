#include <limits.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include "../include/libft.h"

Test(ft_isascii, is_all_ascii_valid)
{
    for (int i = -128; i <= 127; i++) {
        cr_assert(ft_isascii(i) != 0);
    }
}

Test(ft_isascii, is_all_other_int_invalid)
{
    for (int i = -10000000; i < -128; i++) {
        cr_assert(ft_isascii(i) == 0, "A char before -128 is catched");
    }
    for (int i = 128; i <= 1000000; i++) {
        cr_assert(ft_isascii(i) == 0, "A char after 127 is catched");
    }
}
