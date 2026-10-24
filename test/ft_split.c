#include <criterion/criterion.h>
#include "../include/libft.h"
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

char    *__real_ft_strdup(const char *s);
char    *__real_ft_substr(const char *s, unsigned int start, size_t len);
void    *__real_malloc(size_t size);

bool    should_malloc_fail = false;

char    *__real_ft_strdup(const char *s)
{
    return (strdup(s));
}

char    *__wrap_ft_substr(const char *s, unsigned int start, size_t len)
{
    return (strndup(s + start, len));
}

void    *__wrap_malloc(size_t size)
{
    if (should_malloc_fail)
        return (NULL);
    else
        return (__real_malloc(size));
}

void    setup(void)
{
    should_malloc_fail = false;
}

Test(ft_split, if_malloc_fail_return_null, .init=setup)
{
    char    **res;

    should_malloc_fail = true;
    res = ft_split("omedeto shinji", ' ');
    cr_assert_eq(res, NULL);
}

Test(ft_split, should_end_with_null, .init=setup)
{
    char    **res;

    res = ft_split("omedeto shinji", ' ');
    cr_assert_eq(res[2], NULL);
}

Test(ft_split, return_separated_phrase_0, .init=setup)
{
    char    **res;
    char    *test[] = {"bonjour", "tout", "le", "monde", NULL};
    int     i = 0;

    res = ft_split("bonjour tout le monde", ' ');
    while (test[i] && res[i])
    {
        cr_assert_eq(strcmp(test[i], res[i]), 0);
        i++;
    }
    cr_assert_eq(res[i], test[i]);
}

Test(ft_split, return_separeted_phrase_1, .init=setup)
{
    char    **res;
    char    *test[] = {"qui", "de", "nous", "deux?", NULL};
    int     i = 0;

    res = ft_split("qui;de;nous;deux?", ';');
    while (res[i] && test[i])
    {
        cr_assert_eq(strcmp(test[i], res[i]), 0);
        i++;
    }
    cr_assert_eq(res[i], test[i]);
}

Test(ft_split, return_separeted_phrase_2, .init=setup)
{
    char    **res;
    char    *test[] = {"1", "2", "3", "Go", NULL};
    int     i = 0;

    res = ft_split("1,2,3,Go", ',');
    while (res[i] && test[i])
    {
        cr_assert_eq(strcmp(test[i], res[i]), 0);
        i++;
    }
    cr_assert_eq(res[i], test[i]);
}

Test(ft_split, return_string_sep_non_present, .init=setup)
{
    char    **res;
    char    *test[] = {"omedeto shinji", NULL};
    int i = 0;

    res = ft_split("omedeto shinji", ';');
    while (res[i] && test[i])
    {
        cr_assert_eq(strcmp(test[i], res[i]), 0);
        i++;
    }
    cr_assert_eq(res[i], test[i]);
}

Test(ft_split, void_string_should_return_void_string, .init=setup)
{
    char    **res;
    char    *test[] = {"", NULL};
    int     i = 0;

    res = ft_split("", ' ');
    while (res[i] && test[i])
    {
        cr_assert_eq(strcmp(test[i], res[i]), 0);
        i++;
    }
    cr_assert_eq(res[i], test[i]);
}

Test(ft_split, handling_of_multiple_separator_0, .init=setup)
{
    char    **res;
    char    *test[] = {"jane", "doe", NULL};
    int     i = 0;

    res = ft_split("jane_____________doe", '_');
    while (res[i] && test[i])
    {
        cr_assert_eq(strcmp(test[i], res[i]), 0);
        i++;
    }
    cr_assert_eq(test[i], res[i]);
}

Test(ft_split, handling_of_multiple_separator_1, .init=setup)
{
    char    **res;
    char    *test[] = {"face", "my", "fears", NULL};
    int     i = 0;

    res = ft_split("face     my               fears", ' ');
    while (res[i] && test[i])
    {
        cr_assert_eq(strcmp(test[i], res[i]), 0);
        i++;
    }
    cr_assert_eq(test[i], res[i]);
}

Test(ft_split, handling_of_multiple_separator_2, .init=setup)
{
    char    **res;
    char    *test[] = {"my", "sanctuary", NULL};
    int     i = 0;

    res = ft_split("my;;;;;;;;;;;;;;;;;;;;;;;sanctuary", ';');
    while (res[i] && test[i])
    {
        cr_assert_eq(strcmp(test[i], res[i]), 0);
        i++;
    }
    cr_assert_eq(test[i], res[i]);
}

Test(ft_split, handling_of_ending_separators, .init=setup)
{
    char    **res;
    char    *test[] = {"iris", "out", NULL};
    int     i = 0;

    res = ft_split("iris out               ", ' ');
    while (res[i] && test[i])
    {
        cr_assert_eq(strcmp(test[i], res[i]), 0);
        i++;
    }
    cr_assert_eq(test[i], res[i]);
}
