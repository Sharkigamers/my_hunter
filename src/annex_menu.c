/*
** EPITECH PROJECT, 2018
** annex_menu
** File description:
** an annex for menus
*/

#include "my.h"

void lvl(d_window_t *dwd, t_sprite_t *t_spr)
{
    if (dwd->difficulty == 1)
        t_spr->bird.speed.x = 1.75;
    if (dwd->difficulty == 2)
        t_spr->bird.speed.x = 3.06;
    if (dwd->difficulty == 3)
        t_spr->bird.speed.x = 5.0;
    t_spr->score.pos_text.x = 215;
    t_spr->score.pos_text.y = 945;
    t_spr->score.pos_score.x = 415;
    t_spr->score.pos_score.y = 945;
}

void event_for_menu(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr)
{
    dwd->menu.mouse_pos = sfMouse_getPositionRenderWindow(dwd->window);
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        hit_box_play(dwd);
        sfMusic_play(s_and_m->shoot);
        sfMusic_setVolume(s_and_m->shoot, 50);
    }
    if (dwd->event.type == sfEvtClosed) {
        sfRenderWindow_close(dwd->window);
        dwd->menu.open_menu = 0;
    }
    if (dwd->event.type == sfEvtKeyPressed) {
        if (dwd->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(dwd->window);
            dwd->menu.open_menu = 0;
        }
    }
    lvl(dwd, t_spr);
}

void cond_menu(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
                t_sprite_t *t_spr)
{
    while (dwd->menu.open_menu == 1) {
        ini_cond_menu(t_spr, dwd);
        sfText_setCharacterSize(t_spr->score.text, 50);
        sfText_setCharacterSize(t_spr->score.text_score, 50);
        sfText_setPosition(t_spr->score.text, t_spr->score.pos_text);
        sfText_setPosition(t_spr->score.text_score, t_spr->score.pos_score);
        ini_mouse_scope(dwd, m_scp);
        sfRenderWindow_display(dwd->window);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.s_menu, NULL);
        sfRenderWindow_drawText(dwd->window, t_spr->h_score.text_high, NULL);
        sfRenderWindow_drawText(dwd->window, t_spr->h_score.thigh_score, NULL);
        sfText_setString(t_spr->h_score.thigh_score,
                        t_spr->h_score.hsave_score);
        sfRenderWindow_drawText(dwd->window, t_spr->h_score.text_high, NULL);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_for_menu(dwd, s_and_m, t_spr);
    }
}

void event_for_over(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr)
{
    dwd->over.mouse_pos = sfMouse_getPositionRenderWindow(dwd->window);
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        hit_box_over(dwd, t_spr);
        sfMusic_play(s_and_m->shoot);
        sfMusic_setVolume(s_and_m->shoot, 50);
    }
    if (dwd->event.type == sfEvtClosed) {
        sfRenderWindow_close(dwd->window);
        dwd->over.open_over = 0;
    }
    if (dwd->event.type == sfEvtKeyPressed) {
        if (dwd->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(dwd->window);
            dwd->over.open_over = 0;
        }
    }
}

void game_over_menu(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr,
                    m_scope_t *m_scp)
{
    if (t_spr->nexus.life <= 0) {
        t_spr->score.pos_text.x = 476;
        t_spr->score.pos_text.y = 90;
        t_spr->score.pos_score.x = 880;
        t_spr->score.pos_score.y = 90;
        dwd->over.open_over = 1;
    }
    while (dwd->over.open_over == 1) {
        high_score(t_spr);
        ini_mouse_scope(dwd, m_scp);
        sfRenderWindow_display(dwd->window);
        sfRenderWindow_drawSprite(dwd->window, dwd->over.s_over, NULL);
        redef_score(dwd, t_spr);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_for_over(dwd, s_and_m, t_spr);
    }
}
