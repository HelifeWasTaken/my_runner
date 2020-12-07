/*
** EPITECH PROJECT, 2020
** ldebug
** File description:
** lodeus_lib
*/

#pragma once

#ifndef __LODEUS__DEBUG__H__
    #include <lodeus/ctypes.h>
    #define __LODEUS__DEBUG__H__
    #ifdef __LDEBUG__
        #include <lodeus/fd.h>
        #include <lodeus/assert.h>
        #define GET_LOG(n) \
            if (!(n)) { \
                ldprintf(STDOUT_FILENO, "%s - Failed ", #n); \
                ldprintf(STDOUT_FILENO, "In file %s \n", __FILE__); \
                ldprintf(STDOUT_FILENO, "At line %d \n", __LINE__); \
                return (LODEUS_FAIL); \
            }
        #define GET_LOG_ERR(n) \
            if (!(n)) { \
                ldprintf(STDERR_FILENO, "%s - Failed ", #n); \
                ldprintf(STDERR_FILENO, "In file %s \n", __FILE__); \
                ldprintf(STDERR_FILENO, "At line %d \n", __LINE__); \
                return (LODEUS_FAIL); \
            }
    #endif
#endif
