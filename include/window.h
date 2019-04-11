/*
** EPITECH PROJECT, 2018
** window
** File description:
** strcut for window
*/

typedef struct disp_menu
{
    int open_menu;
    sfVector2i mouse_pos;
    sfTexture *t_menu;
    sfSprite *s_menu;
}s_menu_t;

typedef struct game_over
{
    int open_over;
    sfVector2i mouse_pos;
    sfTexture *t_over;
    sfSprite *s_over;
}g_over_t;

typedef struct disp_nexus
{
    sfSprite *sprite;
    sfTexture *texture;
}s_nexus_t;

typedef struct display_window
{
    int difficulty;
    sfRenderWindow *window;
    sfSprite *sprite;
    sfTexture *texture;
    sfEvent event;
    s_nexus_t nexus;
    s_menu_t menu;
    g_over_t over;
}d_window_t;
