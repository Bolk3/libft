#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <limits.h>
#include "../include/libft.h"

Test(ft_isdigit, is_all_digit_valid)
{
    for (int i = '0'; i <= '9'; i++) {
        cr_assert(ft_isdigit(i) != 0);
    }
}

Test(ft_isdigit, is_all_other_invalid)
{
    for (int i = 0; i < '0'; i++) {
        cr_assert(ft_isdigit(i) == 0, "A char before 60 is catched");
    }
    for (int i = 72; i <= 127; i++) {
        cr_assert(ft_isdigit(i) == 0, "A char after 71 is catched");
    }
}
