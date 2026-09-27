#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include "../include/libft.h"

Test(ft_memset, segfault_on_null_pointer, .signal=SIGSEGV)
{
    ft_memset(NULL, 42, 42);
}

Test(ft_memset, set_memory_to_correct_value)
{
    int     test = 300023;
    char    *cpy;

    memset(&test, 42, 4);
    cpy = (char *)&test;
    for (int i = 0; i < 4; i++) {
        cr_assert(cpy[i] == 42);
    }
}
