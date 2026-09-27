#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <limits.h>
#include "../include/libft.h"

Test(isprint, is_all_print_valid)
{
    for (int i = 32; i <= 126; i++) {
        cr_assert(ft_isprint(i) != 0);
    }
}

Test(isprint, is_all_other_invalid)
{
    for (int i = -1000000; i < 32; i++) {
        cr_assert(ft_isprint(i) == 0, "A char before 32 is catched");
    }
    for (int i = 127; i <= 1000000; i++) {
        cr_assert(ft_isprint(i) == 0, "A char after 127 is catched");
    }
}
