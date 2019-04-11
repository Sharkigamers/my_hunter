/*
** EPITECH PROJECT, 2018
** bar
** File description:
** disp bars
*/

#include "my.h"

void nexus_life(t_sprite_t *t_spr)
{
    if (sfSprite_getPosition(t_spr->bird.sprite).x >= 1450) {
        sfSprite_setPosition(t_spr->bird.sprite, t_spr->bird.pos_pop);
        t_spr->nexus.life -= 1;
        t_spr->bar.rect_bar.top += 89;
    }
}

void disp_bar(d_window_t *dwd, t_sprite_t *t_spr)
{
    if (t_spr->nexus.life == 3)
        sfRenderWindow_drawSprite(dwd->window, t_spr->bar.s_life_1, NULL);
    if (t_spr->nexus.life == 2) {
        sfSprite_setTextureRect(t_spr->bar.s_life_2, t_spr->bar.rect_bar);
        sfRenderWindow_drawSprite(dwd->window, t_spr->bar.s_life_2, NULL);
    }
    if (t_spr->nexus.life == 1) {
        sfSprite_setTextureRect(t_spr->bar.s_life_3, t_spr->bar.rect_bar);
        sfRenderWindow_drawSprite(dwd->window, t_spr->bar.s_life_3, NULL);
    }
}
