/*
** EPITECH PROJECT, 2018
** window disp
** File description:
** disp the window
*/

#include "my.h"

void ini_menu(d_window_t *dwd)
{
    dwd->menu.t_menu = sfTexture_createFromFile
        ("assets/bckg/menu.jpg", NULL);
    dwd->menu.s_menu = sfSprite_create();
    dwd->menu.open_menu = 1;
    dwd->difficulty = 0;
    sfSprite_setTexture(dwd->menu.s_menu, dwd->menu.t_menu, sfTrue);
}

void ini_over(d_window_t *dwd)
{
    dwd->over.t_over= sfTexture_createFromFile
        ("assets/bckg/game_over.jpg", NULL);
    dwd->over.s_over = sfSprite_create();
    dwd->over.open_over = 0;
    sfSprite_setTexture(dwd->over.s_over, dwd->over.t_over, sfTrue);
}

sfRenderWindow *create_mywindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode vd_md = {width, height, 32};

    window = sfRenderWindow_create(vd_md, "MyHunter", sfResize | sfClose, NULL);
    return (window);
}

void background(d_window_t *dwd)
{
    sfVector2f pos_nexus;

    pos_nexus.x = 1625;
    pos_nexus.y = 135;
    sfSprite_setTexture(dwd->sprite, dwd->texture, sfTrue);
    sfRenderWindow_drawSprite(dwd->window, dwd->sprite, NULL);
    sfSprite_setTexture(dwd->nexus.sprite, dwd->nexus.texture, sfTrue);
    sfSprite_setPosition(dwd->nexus.sprite, pos_nexus);
    sfRenderWindow_drawSprite(dwd->window, dwd->nexus.sprite, NULL);
}
