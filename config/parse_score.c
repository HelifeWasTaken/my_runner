/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** parse_score
*/

#include <my_runner/runner.h>
#include <my_runner/score.h>
#include <stdio.h>

static void free_score_board(score_t *head)
{
    if (head) {
        if (head->next)
            free_score_board(head->next);
        free(head->username);
        free(head);
    }
}

static score_t *get_score_board(char *filename)
{
    score_t *score = NULL;
    size_t buffer_index = 0;
    char *buffer = NULL;
    FILE *file = fopen(filename, "ra");

    if (file == NULL) {
        SHOW_ERROR_LOG_OPEN_FILE_FAIL("./config/score.config");
        return (NULL);
    }
    while (getline(&buffer, &buffer_index, file) > 0) {
        if (add_score_node(&score, buffer) == false) {
            free_score_board(score);
            return (NULL);
        }
    }
    free(buffer);
    fclose(file);
    return (score);
}

static char *concat_score_board_top(score_t *head)
{
    char *buf = my_strdup("Top 3: \n");
    int i = 0;

    for (; i < 3 && head; i++) {
        buf = concat_string(buf, my_itoa(i + 1, "0123456789"));
        buf = concat_string(buf, ": ");
        buf = concat_string(buf, concat_string(head->username, " - "));
        buf = concat_string(buf, my_itoa(head->score, "0123456789"));
        buf = concat_string(buf, "\n");
        head = head->next;
    }
    for (; i < 3; i++) {
        buf = concat_string(buf, my_itoa(i, "0123456789"));
        buf = concat_string(buf, ": ");
        buf = concat_string(buf, "NA - NA\n");
    }
    return (buf);
}

void append_score_to_file(unsigned long long score, char *username)
{
    FILE *score_file = fopen("./config/score.config", "a");
    char *buf_1 = NULL;

    if (score_file == NULL) {
        SHOW_ERROR_LOG_OPEN_FILE_FAIL("./config/score.config");
        return;
    }
    if (username == NULL)
        return;
    buf_1 = my_itoa(score, "0213456789");
    fwrite(username, sizeof(char), my_strlen(username), score_file);
    fwrite(":", sizeof(char), 1, score_file);
    fwrite(buf_1, sizeof(char), my_strlen(buf_1), score_file);
    fwrite("\n", sizeof(char), 1, score_file);
    free(buf_1);
    free(username);
    fclose(score_file);
}

char *get_leaderboard_in_str(void)
{
    score_t *head = get_score_board("./config/score.config");
    char *buf = NULL;

    if (head)
        bubble_sort_score_board(&head);
    buf = concat_score_board_top(head);
    free_score_board(head);
    return (buf);
}
