#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <signal.h>
#include <strings.h>
#include <wchar.h>
#include "../include/libft.h"

Test(ft_bzero, segfault_on_null_pointer, .signal =SIGSEGV)
{
    ft_bzero(NULL, 42);
}

Test(ft_bzero, set_0_to_every_bytes)
{
    char    test[5] = {56, 23, 45, 23, 112};
    bzero(test, 5);
    for (int i = 0; i < 5; i++) {
        cr_assert_eq(test[i], 0);
    }
}
