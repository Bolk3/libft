#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <limits.h>
#include "../include/libft.h"

Test(ft_isalpha, is_all_lower_valid) {
    for (int i = 'a'; i <= 'z'; i++) {
        cr_assert(ft_isalpha(i) != 0);
    }
}

Test(ft_isalpha, is_all_upper_valid) {
    for (int i = 'A'; i <= 'Z'; i++) {
        cr_assert(ft_isalpha(i) != 0);
    }
}

Test(ft_isalpha, is_all_other_invalid) {
    for (int i = 0; i < 'A'; i++) {
        cr_assert(ft_isalpha(i) == 0, "A char beteen \\0 and @ is catched");
    }
    for (int i = 'Z' + 1; i < 'a'; i++) {
        cr_assert(ft_isalpha(i) == 0, "A char between [ and ` is catched");
    }
    for (int i = 'z' + 1; i <= 127; i++) {
        cr_assert(ft_isalpha(i) == 0, "A char between { and DEL is catched");
    }
}
