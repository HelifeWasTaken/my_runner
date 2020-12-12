/*
** EPITECH PROJECT, 2020
** my_criterion_header_file
** File description:
** header_file_for_unit_tests
*/

#ifndef __MY_CRITERION__H__
#define __MY_CRITERION__H__
#include <criterion/criterion.h>
#include <criterion/hooks.h>
#include <criterion/logging.h>
#include <criterion/redirect.h>
#include <my_all.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <limits.h>
#define cr_stdout .init = cr_redirect_stdout
#define cr_stderr .init = cr_redirect_stderr
#define cr_redirect_all \
    cr_redirect_stdout(); \
    cr_redirect_stderr();
#endif
