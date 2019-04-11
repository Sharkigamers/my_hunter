/*
** EPITECH PROJECT, 2018
** hit box menu
** File description:
** hit box for menus
*/

#include "my.h"

void hit_box_play(d_window_t *dwd)
{
    if (dwd->menu.mouse_pos.x >= 857 && dwd->menu.mouse_pos.y >= 148 &&
        dwd->menu.mouse_pos.x <= 1185 && dwd->menu.mouse_pos.y <= 280) {
        dwd->difficulty = 1;
        dwd->menu.open_menu = 0;
    }
    if (dwd->menu.mouse_pos.x >= 828 && dwd->menu.mouse_pos.y >= 482 &&
        dwd->menu.mouse_pos.x <= 1214 && dwd->menu.mouse_pos.y <= 630) {
        dwd->difficulty = 2;
        dwd->menu.open_menu = 0;
    }
    if (dwd->menu.mouse_pos.x >= 860 && dwd->menu.mouse_pos.y >= 837 &&
        dwd->menu.mouse_pos.x <= 1200 && dwd->menu.mouse_pos.y <= 989) {
        dwd->difficulty = 3;
        dwd->menu.open_menu = 0;
        }
    if (dwd->menu.mouse_pos.x >= 13 && dwd->menu.mouse_pos.y >= 598 &&
        dwd->menu.mouse_pos.x <= 364 && dwd->menu.mouse_pos.y <= 933) {
        dwd->menu.open_menu = 0;
        sfRenderWindow_close(dwd->window);
    }
}

void hit_box_over(d_window_t *dwd, t_sprite_t *t_spr)
{
    if (dwd->over.mouse_pos.x >= 408 && dwd->over.mouse_pos.y >= 648 &&
        dwd->over.mouse_pos.x <= 870 && dwd->over.mouse_pos.y <= 836) {
        dwd->over.open_over = 0;
        dwd->menu.open_menu = 1;
        t_spr->bar.rect_bar.left = 124;
        t_spr->bar.rect_bar.top = 178;
        t_spr->bar.rect_bar.height = 80;
        t_spr->bar.rect_bar.width = 310;
    }
    if (dwd->over.mouse_pos.x >= 1124 && dwd->over.mouse_pos.y >= 652 &&
        dwd->over.mouse_pos.x <= 1578 && dwd->over.mouse_pos.y <= 834) {
        dwd->over.open_over = 0;
        dwd->menu.open_menu = 0;
        sfRenderWindow_close(dwd->window);
    }
}

void redef_score(d_window_t *dwd, t_sprite_t *t_spr)
{
    sfText_setCharacterSize(t_spr->score.text, 100);
    sfText_setCharacterSize(t_spr->score.text_score, 100);
    sfText_setPosition(t_spr->score.text, t_spr->score.pos_text);
    sfText_setPosition(t_spr->score.text_score, t_spr->score.pos_score);
    sfRenderWindow_drawText(dwd->window, t_spr->score.text, NULL);
    sfText_setString(t_spr->score.text_score, my_itoa(t_spr->score.score));
    sfRenderWindow_drawText(dwd->window, t_spr->score.text_score, NULL);
}

void ini_cond_menu(t_sprite_t *t_spr, d_window_t *dwd)
{
    high_score(t_spr);
    t_spr->nexus.life = 3;
    t_spr->bullet = 1;
    t_spr->bar.rect_ammo.width = 150;
    dwd->over.open_over = 0;
    t_spr->score.score = 0;
}
