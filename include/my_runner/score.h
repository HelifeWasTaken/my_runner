/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** score
*/

#pragma once

#ifndef __MY__RUNNER__SCORE__H__
    #define __MY__RUNNER__SCORE__H__
    typedef struct score_info {
        char *username;
        unsigned long long score;
        struct score_info *next;
    } score_t;
    char *get_leaderboard_in_str(void);
    bool add_score_node(score_t **head, char *buffer);
    void bubble_sort_score_board(score_t **head);
    void append_score_to_file(unsigned long long score, char *username);
#endif
