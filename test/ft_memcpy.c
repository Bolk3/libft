#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <criterion/logging.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <wchar.h>
#include "../include/libft.h"

Test(ft_memcpy, is_copying_full_lenght)
{
    char    *src = "test test test";
    char    *dest = malloc(strlen(src) + 1);

    if (!dest)
        cr_assert(false, "cannot malloc enought memory for test");
    dest = ft_memcpy(dest, src, strlen(src) + 1);
    for (int i = 0; src[i]; i++) {
        cr_expect_eq(src[i], dest[i]);
    }
    free(dest);
}

Test(ft_memcpy, segfault_on_void_dest, .signal=11)
{
    char    *src = "test";

    ft_memcpy(NULL, src, 4);
}

Test(ft_memcpy, segfault_on_void_src, .signal=11)
{
    char    dest[5];

    ft_memcpy(dest, NULL, 5);
}
