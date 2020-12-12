/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <my_runner.h>
#include <my_stdio.h>

static void show_help(void)
{
    my_printf(YELLOW"MY_RUNNER\n\n");
    my_printf(BLUE"\tTo launch it use :" GREEN" ./my_runner [map]\n");
    my_printf(BLUE"\tTo see this help use:" GREEN" ./my_runner -h\n");
    my_printf(PURPLE"\nDESCRIPTION:\n\n");
    my_printf(CYAN"\t\tTODO\n\n");
    my_printf(RED"Mattis DALLEAU\n"DEFAULT);
}

static int usage(int ac, char **av)
{
    if (ac > 2) {
        my_dprintf(2, "my_runner: You have given too ");
        my_dprintf(2, "much arguments\nTry : /my_runner -h for the help\n");
        return (84);
    }
    if (!my_strcmp(av[1], "-h")) {
        show_help();
        return (0);
    }
    my_dprintf(2, RED"my_runner :" YELLOW"\n\tYou have given a wrong"
                                        " argument !\n"DEFAULT);
    my_dprintf(2, CYAN"You can try :" GREEN"\n\t./my_runner -h to"
                                            " show the help\n"DEFAULT);
    return (84);
}

int main(int ac, char **av)
{
    game_manager_t manager;
    scene_t scene = init_scene();

    if (ac != 1)
        return (usage(ac, av));
    manager.window = CREATE_WINDOW(WINDOW_SIZE, WINDOW_NAME);
    SET_FRAME_LIMIT(manager.window, 60);
    manager.clock = sfClock_create();
    while (sfRenderWindow_isOpen(manager.window)) {
        while (CHECK_WINDOW_EVENT(manager.window, manager.event)) {
            if (manager.event.type == sfEvtClosed)
                CLOSE_WINDOW(manager.window);
        }
        draw_all_game(&scene, &manager);
   }
    return (0);
}
