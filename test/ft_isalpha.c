#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include "../include/libft.h"

Test(isalpha, recon_lower) {
    for (int i = 'a'; i <= 'z'; i++) {
        cr_assert(ft_isalpha(i) != 0);
    }
}

Test(isalpha, recon_upper) {
    for (int i = 'A'; i <= 'Z'; i++) {
        cr_assert(ft_isalpha(i) != 0);
    }
}

Test(isalpha, recon_not_alpha) {
    for (int i = 0; i < 'A'; i++) {
        cr_assert(ft_isalpha(i) == 0);
    }
    for (int i = 'Z' + 1; i < 'a'; i++) {
        cr_assert(ft_isalpha(i) == 0);
    }
    for (int i = 'z' + 1; i <= 127; i++) {
        cr_assert(ft_isalpha(i) == 0);
    }
}
