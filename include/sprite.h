/*
** EPITECH PROJECT, 2018
** sprite
** File description:
** strcut for sprite
*/

#include "my.h"

typedef struct nexus_life
{
    int life;
}n_life_t;

typedef struct my_high_score
{
    int high_score;
    char *hsave_score;
    sfText *text_high;
    sfFont *font_high;
    sfVector2f pos_high;
    sfText *thigh_score;
    sfFont *fhigh_score;
    sfVector2f phigh_score;
}h_score_t;

typedef struct my_score
{
    int score;
    sfText *text_score;
    sfFont *font_score;
    sfVector2f pos_score;
    sfText *text;
    sfFont *font;
    sfVector2f pos_text;
}m_score_t;

typedef struct disp_bar
{
    sfSprite *s_ammo;
    sfTexture *t_ammo;
    sfIntRect rect_ammo;
    sfVector2f pos_ammo;
    sfIntRect rect_bar;
    sfVector2f pos_bar;
    sfSprite *s_life_1;
    sfSprite *s_life_2;
    sfSprite *s_life_3;
    sfTexture *t_life_1;
    sfTexture *t_life_2;
    sfTexture *t_life_3;
}d_bar_t;

typedef struct mouse_scop
{
    sfVector2i mouse_pos;
    sfVector2f pos;
    sfTexture *scope;
    sfSprite *sprite_scope;
}m_scope_t;

typedef struct sprite_bird
{
    sfVector2f speed;
    sfVector2f pos_pop;
    sfIntRect area;
    sfClock *clock_bird;
    sfTime time_bird;
    float sec_bird;
    sfSprite *sprite;
    sfTexture *texture;
    int reset;
}s_bird_t;

typedef struct tot_sprite
{
    int bullet;
    m_score_t score;
    h_score_t h_score;
    n_life_t nexus;
    s_bird_t bird;
    d_bar_t bar;
}t_sprite_t;
