/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** font
*/

#pragma once

#ifndef __RUNNER__FONT__H__
    #define __RUNNER__FONT__H__
    #include <SFML/Graphics.h>

    typedef struct {
        sfFont *font_score;
        sfText *text_score;
    } text_t;

    #define FONT_SCORE_ASSET        "asset/font/kemco.ttf"
#endif