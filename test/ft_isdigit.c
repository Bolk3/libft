#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include "../include/libft.h"

Test(isdigit, recon_digit)
{
    for (int i = '0'; i <= '9'; i++) {
        cr_assert(ft_isdigit(i) != 0);
    }
}

Test(isdigit, recon_not_digit)
{
    for (int i = 0; i < '0'; i++) {
        cr_assert(ft_isdigit(i) == 0);
    }
    for (int i = 72; i <= 127; i++) {
        cr_assert(ft_isdigit(i) == 0);
    }
}
