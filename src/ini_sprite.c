/*
** EPITECH PROJECT, 2018
** ini_sprite
** File description:
** initialisation of sprites
*/

#include "my.h"

void bullet(t_sprite_t *t_spr)
{
    t_spr->bar.rect_ammo.left = 0;
    t_spr->bar.rect_ammo.top = 0;
    t_spr->bar.rect_ammo.height = 500;
    t_spr->bar.rect_ammo.width = 500;
    t_spr->bar.pos_ammo.x = 10;
    t_spr->bar.pos_ammo.y = 900;
    t_spr->bar.t_ammo = sfTexture_createFromFile("assets/sprite/ammo.png",
                                                NULL);
    t_spr->bar.s_ammo = sfSprite_create();
    sfSprite_setTexture(t_spr->bar.s_ammo, t_spr->bar.t_ammo, sfTrue);
    sfSprite_setTextureRect(t_spr->bar.s_ammo, t_spr->bar.rect_ammo);
    sfSprite_setPosition(t_spr->bar.s_ammo, t_spr->bar.pos_ammo);
}

void set_pos_tab(t_sprite_t *t_spr)
{
    t_spr->bar.rect_bar.left = 124;
    t_spr->bar.rect_bar.top = 178;
    t_spr->bar.rect_bar.height = 80;
    t_spr->bar.rect_bar.width = 310;
    t_spr->bar.pos_bar.x = 1600;
    t_spr->bar.pos_bar.y = 20;
}

void tab_init(t_sprite_t *t_spr)
{
    set_pos_tab(t_spr);
    t_spr->bar.t_life_1 = sfTexture_createFromFile
        ("assets/sprite/tab_bar.png", NULL);
    t_spr->bar.s_life_1 = sfSprite_create();
    t_spr->bar.t_life_2 = sfTexture_createFromFile
        ("assets/sprite/tab_bar.png", NULL);
    t_spr->bar.s_life_2 = sfSprite_create();
    t_spr->bar.t_life_3 = sfTexture_createFromFile
        ("assets/sprite/tab_bar.png", NULL);
    t_spr->bar.s_life_3 = sfSprite_create();
    sfSprite_setTexture(t_spr->bar.s_life_1, t_spr->bar.t_life_1, sfTrue);
    sfSprite_setTexture(t_spr->bar.s_life_2, t_spr->bar.t_life_2, sfTrue);
    sfSprite_setTexture(t_spr->bar.s_life_3, t_spr->bar.t_life_3, sfTrue);
    sfSprite_setTextureRect(t_spr->bar.s_life_1, t_spr->bar.rect_bar);
    sfSprite_setPosition(t_spr->bar.s_life_1, t_spr->bar.pos_bar);
    sfSprite_setPosition(t_spr->bar.s_life_2, t_spr->bar.pos_bar);
    sfSprite_setPosition(t_spr->bar.s_life_3, t_spr->bar.pos_bar);
}

void ini_score(t_sprite_t *t_spr)
{
    t_spr->score.score = 0;
    t_spr->score.font = sfFont_createFromFile("assets/text/Cuadra-Bold.otf");
    t_spr->score.font_score = sfFont_createFromFile
        ("assets/text/Cuadra-Bold.otf");
    t_spr->score.text = sfText_create();
    t_spr->score.text_score = sfText_create();
    sfText_setFont(t_spr->score.text, t_spr->score.font);
    sfText_setColor(t_spr->score.text, sfWhite);
    sfText_setFont(t_spr->score.text_score, t_spr->score.font_score);
    sfText_setColor(t_spr->score.text_score, sfWhite);
    t_spr->score.pos_text.x = 215;
    t_spr->score.pos_text.y = 945;
    t_spr->score.pos_score.x = 415;
    t_spr->score.pos_score.y = 945;
    sfText_setCharacterSize(t_spr->score.text, 50);
    sfText_setCharacterSize(t_spr->score.text_score, 50);
    sfText_setString(t_spr->score.text, "Score :");
    sfText_setPosition(t_spr->score.text, t_spr->score.pos_text);
    sfText_setPosition(t_spr->score.text_score, t_spr->score.pos_score);
}

void highest_score(t_sprite_t *t_spr)
{
    t_spr->h_score.font_high = sfFont_createFromFile
        ("assets/text/Cuadra-Bold.otf");
    t_spr->h_score.fhigh_score = sfFont_createFromFile
        ("assets/text/Cuadra-Bold.otf");
    t_spr->h_score.text_high = sfText_create();
    t_spr->h_score.thigh_score = sfText_create();
    sfText_setFont(t_spr->h_score.text_high, t_spr->h_score.font_high);
    sfText_setFont(t_spr->h_score.thigh_score, t_spr->h_score.fhigh_score);
    sfText_setColor(t_spr->h_score.text_high, sfWhite);
    sfText_setColor(t_spr->h_score.thigh_score, sfWhite);
    t_spr->h_score.pos_high.x = 1400;
    t_spr->h_score.pos_high.y = 100;
    t_spr->h_score.phigh_score.x = 1400;
    t_spr->h_score.phigh_score.y = 200;
    sfText_setCharacterSize(t_spr->h_score.text_high, 75);
    sfText_setCharacterSize(t_spr->h_score.thigh_score, 75);
    sfText_setString(t_spr->h_score.text_high, "High score");
    sfText_setPosition(t_spr->h_score.text_high, t_spr->h_score.pos_high);
    sfText_setPosition(t_spr->h_score.thigh_score, t_spr->h_score.phigh_score);
}
