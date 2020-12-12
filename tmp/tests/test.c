/*
** EPITECH PROJECT, 2020
** test.c
** File description:
** lodeus_lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <lodeus/all.h>
#include <signal.h>
#include <stddef.h>

/* test lputchar */

Test(test_putchar, test_basic_putchar_stdout, .init=cr_redirect_stdout)
{
    ldputchar(1, 'a');
    lputchar('a');
    cr_assert_stdout_eq_str("aa");
}

Test(test_putchar, test_basic_putchar_stderr, .init=cr_redirect_stderr)
{
    ldputchar(2, 'a');
    cr_assert_stderr_eq_str("aa");
}

/* test lputs */

Test(test_puts, test_basic_puts_stderr, .init=cr_redirect_stderr)
{
    ldputs(2, "stderr");
    cr_assert_stderr_eq_str("stderr\n");
}

Test(test_puts, test_basic_puts_stdout, .init=cr_redirect_stdout)
{
    lputs("normal");
    ldputs(1, "stdout");
    cr_assert_stdout_eq_str("normal\nstdout\n");
}

/* test_lputnbr */

Test(test_putnbr, test_basic_putnbr_stdout, .init=cr_redirect_stdout)
{
    lputnbr(1111);
    ldputnbr(1, 1111);
    cr_assert_stdout_eq_str("11111111");
}

Test(test_putnbr, test_basic_putnbr_stderr, .init=cr_redirect_stderr)
{
    ldputnbr(2, 2222);
    cr_assert_stderr_eq_str("2222");
}

/* test_lswap */

Test(test_swap, test_basic_swap)
{
    int a = 5;
    int b = 3;

    lswap(&a, &b);
    cr_assert_eq(a, 3);
    cr_assert_eq(b, 5);
}

/* test_lstrcat */

Test(test_strcat, test_cat)
{
    char *dest = malloc(sizeof(char) * 20);
    char *src = "o friend";

    dest[0] = 'H';
    dest[1] = 'e';
    dest[2] = 'l';
    dest[3] = 'l';
    cr_assert_str_eq(lstrcat(dest, src), "Hello friend");
    free(dest);
}

/* test_lstrcmp */

Test(test_strcmp, check_all)
{
    char *s1 = "hello";
    char *s1_cpy = "hello";
    char *s2 = "bello";

    cr_assert_eq(lstrcmp(s1, s2), 1);
    cr_assert_eq(lstrcmp(s2, s1), -1);
    cr_assert_eq(lstrcmp(s1, s1_cpy), 0);
}

/* test lstrcpy */

Test(test_strcpy, copy_str)
{
    char *src = "Hello";
    char *dest = malloc(sizeof(char) * (lstrlen(src) + 1));

    lstrcpy(dest, src);
    cr_assert_str_eq(src, dest);
    free(dest);
}

/* test lstrdup */

Test(test_strdup, copy_and_malloc_str)
{
    char *src = "Hello";
    char *dest = lstrdup(src);

    cr_assert_str_eq(src, dest);
    cr_assert_neq(src, dest);
    free(dest);
}

/* test lrevstr */

Test(test_revstr, reverse_a_simple_str)
{
    char *test = lstrdup("hello");
    char *test2 = lstrdup("helloa");

    cr_assert_str_eq(lrevstr(test), "olleh");
    cr_assert_str_eq(lrevstr(test2), "aolleh");
    free(test);
    free(test2);
}

/* test lstrncat */

Test(test_strncat, test_ncat)
{
    char *dest = malloc(sizeof(char) * 20);
    char *src = "o friend";

    dest[0] = 'H';
    dest[1] = 'e';
    dest[2] = 'l';
    dest[3] = 'l';
    cr_assert_str_eq(lstrncat(dest, src, 5), "Hello fri");
    free(dest);
}

/* test lnblen */

Test(lnblen_test, test_multiple_bases_and_all)
{
    cr_assert_eq(lnblen(567), 3);
    cr_assert_eq(lnblen(-567), 4);
    cr_assert_eq(lnbulen(99999999), 8);
    cr_assert_eq(lnbbaselen(5, 2), 3);
}

/* lfmod */

Test(lfmod_test, test_mod)
{
    cr_assert_eq(lfmod(5678.78, 10), 8);
}

#ifdef __USE__FAIL__

/* loderound */

Test(loderound_test, test_round)
{
    lprintf("%d\n", (int)loderound(5678.78, 3));
    cr_assert_eq((int)loderound(5678.78, 2), 5679);
}

#endif

/* lbzero lmemset */

Test(test_lmemset, set_all_to_zero_then_ones)
{
    char *str = malloc(sizeof(char) * 10);

    lmemset(str, 1, sizeof(char) * 10);
    cr_assert_eq(str[3], 1);
    lmemset(str, 0, sizeof(char) * 10);
    cr_assert_neq(str[3], 1);
    cr_assert_eq(str[3], 0);
    free(str);
}

/* llmemcmp */

Test(test_llmemcmp, do_all_cases)
{
    char *str = lstrdup("Hello");
    char *str2 = lstrdup("Hello");
    char *str3 = lstrdup("Hzllo");

    cr_assert_eq(lmemcmp(str, str2, 5), 0);
    cr_assert_eq(lmemcmp(str, str3, 5), 1);
    cr_assert_eq(lmemcmp(str3, str, 5), -1);
    free(str);
    free(str2);
    free(str3);
}

/* llmemcpy */

Test(test_llmemcpy, copy_direct)
{
    char *str = lstrdup("Hello");
    char *str2 = malloc(sizeof(char) * (lstrlen(str) + 1));

    lmemcpy(str2, str, lstrlen(str) + 1);
    cr_assert_str_eq(str, str2);
    free(str);
    free(str2);
}

/* lmemmove */

Test(lmemmove, copy_with_buffer)
{
    char *str = lstrdup("Hello");
    char *str2 = malloc(sizeof(char) * (lstrlen(str) + 1));

    lmemcpy(str2, str, lstrlen(str) + 1);
    cr_assert_str_eq(str, str2);
    free(str);
    free(str2);
}

/* lprintloop */

Test(lprintloop, print_ten_zeroes, .init=cr_redirect_stdout)
{
    lprint_loop('0', 10);

    cr_assert_stdout_eq_str("0000000000");
}

/* lstrrealocat */

Test(lstrrealocat, concat_two_strings_that_has_not_enough_space)
{
    char *str = lstrdup("hello");
    char *str2 = lstrdup("World");
    char *new;

    new = lstr_realocat(str, str2);
    cr_assert_str_eq(new, "helloWorld");
    free(new);
}

/* lstrlen */

Test(lstrlen, calculate_str_len)
{
    cr_assert_eq(lstrlen(""), 0);
    cr_assert_eq(lstrlen("hello"), 5);
    cr_assert_eq(lstrlen("a"), 1);
}

/* lsplit */

Test(lsplit, create_an_array_of_array_of_char,
        .init=cr_redirect_stdout)
{
    char **str = lsplit("hello\nworld\nnice", '\n');

    for (size_t i = 0; str[i]; i++)
        lputs(str[i]);
    cr_assert_stdout_eq_str("hello\nworld\nnice\n");
}

