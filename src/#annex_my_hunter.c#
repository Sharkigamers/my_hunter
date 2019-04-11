/*
** EPITECH PROJECT, 2018
** annex_my_hunter
** File description:
** annex of cond for my_hunter
*/

#include "my.h"

void start_cond(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
                t_sprite_t *t_spr)
{
    sfVector2f origin_scope = {126 / 2, 126 / 2};

    set_music(s_and_m);
    dwd->texture = sfTexture_createFromFile("assets/bckg/bck.jpg", NULL);
    dwd->nexus.texture = sfTexture_createFromFile("assets/bckg/nexus.png",
                                                NULL);
    m_scp->scope = sfTexture_createFromFile("assets/sprite/scope.png", NULL);
    m_scp->sprite_scope = sfSprite_create();
    dwd->window = create_mywindow(1920, 1080);
    dwd->sprite = sfSprite_create();
    dwd->nexus.sprite = sfSprite_create();
    sfRenderWindow_setMouseCursorVisible(dwd->window, sfFalse);
    s_and_m->start_sound = music_create();
    ini_menu(dwd);
    ini_over(dwd);
    sfSprite_setOrigin(m_scp->sprite_scope, origin_scope);
    tab_init(t_spr);
    bullet(t_spr);
    ini_score(t_spr);
}

void destroy_menu_and_music(d_window_t *dwd, s_music_t *s_and_m)
{
    sound_destroy(s_and_m->start_sound);
    sfMusic_destroy(s_and_m->shoot);
    sfMusic_destroy(s_and_m->reload);
    sfMusic_destroy(s_and_m->empty);
    sfTexture_destroy(dwd->menu.t_menu);
    sfSprite_destroy(dwd->menu.s_menu);
    sfTexture_destroy(dwd->nexus.texture);
    sfSprite_destroy(dwd->nexus.sprite);
    sfTexture_destroy(dwd->texture);
    sfSprite_destroy(dwd->sprite);
    sfRenderWindow_destroy(dwd->window);
}

void destroy_scope_tab_bird(m_scope_t *m_scp, t_sprite_t *t_spr)
{
    sfTexture_destroy(m_scp->scope);
    sfSprite_destroy(m_scp->sprite_scope);
    sfText_destroy(t_spr->score.text_score);
    sfFont_destroy(t_spr->score.font_score);
    sfText_destroy(t_spr->score.text);
    sfFont_destroy(t_spr->score.font);
    sfClock_destroy(t_spr->bird.clock_bird);
    sfTexture_destroy(t_spr->bird.texture);
    sfSprite_destroy(t_spr->bird.sprite);
    sfTexture_destroy(t_spr->bar.t_ammo);
    sfSprite_destroy(t_spr->bar.s_ammo);
    sfTexture_destroy(t_spr->bar.t_life_1);
    sfTexture_destroy(t_spr->bar.t_life_2);
    sfTexture_destroy(t_spr->bar.t_life_3);
    sfSprite_destroy(t_spr->bar.s_life_1);
    sfSprite_destroy(t_spr->bar.s_life_2);
    sfSprite_destroy(t_spr->bar.s_life_3);
}

void destroy_high_score(t_sprite_t *t_spr)
{
    sfText_destroy(t_spr->h_score.text_high);
    sfText_destroy(t_spr->h_score.thigh_score);
    sfFont_destroy(t_spr->h_score.font_high);
    sfFont_destroy(t_spr->h_score.fhigh_score);
}

void destroy_all(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
                t_sprite_t *t_spr)
{
    destroy_menu_and_music(dwd, s_and_m);
    destroy_scope_tab_bird(m_scp, t_spr);
    destroy_high_score(t_spr);
}
