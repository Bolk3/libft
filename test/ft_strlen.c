#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include "../include/libft.h"

Test(ft_strlen, is_size_null_valid)
{
    cr_assert(ft_strlen("") == 0);
}

Test(ft_strlen, is_stopping_at_first_null_byte)
{
    char    test[] = {'a', 'b', 'c', 0, 'd', 0};
    cr_assert(ft_strlen(test) == 3);
}

Test(ft_strlen, sefault_on_null_pointer, .signal = SIGSEGV)
{
    ft_strlen(NULL);
}

Test(ft_strlen, nominal)
{
    cr_assert(ft_strlen("hello") == strlen("hello"));
}

Test(ft_strlen, long_string)
{
    char    *test = "abc def ghi jkl mno pqrs tuv wxyz ABC DEF GHI JKL MNO PQRS TUV WXYZ !§ $%& /() =?* '<> #|; ²³~ @`´ ©«» ¤¼× {} abc def ghi jkl mno pqrs tuv wxyz ABC DEF GHI JKL MNO PQRS TUV WXYZ !§ $%& /() =?* '<> #|; ²³~ @`´ ©«» ¤¼× {} abc def ghi jkl mno pqrs tuv wxyz ABC DEF GHI JKL MNO PQRS TUV WXYZ !§ $%& /() =?* '<> #|; ²³~ @`´ ©«» ¤¼× {} abc def ghi jkl mno pqrs tuv wxyz ABC DEF GHI JKL MNO PQRS TUV WXYZ !§ $%& /() =?* '<> #|; ²³~ @`´ ©«» ¤¼× {} abc def ghi jkl mno pqrs tuv wxyz ABC DEF GHI JKL MNO PQRS TUV WXYZ !§ $%& /() =?* '<> #|; ²³~ @`´ ©«» ¤¼× {} abc def ghi jkl mno pqrs tuv wxyz ABC DEF GHI JKL MNO PQRS TUV WXYZ !§ $%& /() =?* '<> #|; ²³~ @`´ ©«» ¤¼× {} abc def ghi jkl mno pqrs tuv wxyz ABC DEF GHI JKL MNO PQRS TUV WXYZ !§ $%& /() =?* '<> #|; ²³~ @`´ ©«» ¤¼× {}abc def ghi jkl mno pqrs tuv wxyz ABC DEF GHI";
    cr_assert(ft_strlen(test) == strlen(test));
}
