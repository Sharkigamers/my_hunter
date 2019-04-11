/*
** EPITECH PROJECT, 2018
** event
** File description:
** the event of the my_hunter
*/

#include "my.h"

void event_shoot(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr,
                m_scope_t *m_scp)
{
    if (dwd->event.mouseButton.button == sfMouseLeft) {
        if (t_spr->bullet == 0) {
            sfMusic_play(s_and_m->empty);
            sfMusic_setVolume(s_and_m->empty, 50);
        }
        if (t_spr->bullet == 1) {
            sfMusic_play(s_and_m->shoot);
            sfMusic_setVolume(s_and_m->shoot, 50);
            hit_box(m_scp, t_spr);
            t_spr->bar.rect_ammo.width = 150;
            sfSprite_setTextureRect(t_spr->bar.s_ammo, t_spr->bar.rect_ammo);
            sfRenderWindow_drawSprite(dwd->window, t_spr->bar.s_ammo, NULL);
        }
    }
}

void event_reload(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr)
{
    if (t_spr->bullet == 0)
        if (dwd->event.mouseButton.button == sfMouseRight) {
            t_spr->bar.rect_ammo.width = 500;
            sfSprite_setTextureRect(t_spr->bar.s_ammo, t_spr->bar.rect_ammo);
            sfRenderWindow_drawSprite(dwd->window, t_spr->bar.s_ammo, NULL);
            sfMusic_play(s_and_m->reload);
            t_spr->bullet = 1;
        }
}

void in_event(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
                t_sprite_t *t_spr)
{
    if (dwd->event.type == sfEvtClosed)
        sfRenderWindow_close(dwd->window);
    if (dwd->event.type == sfEvtKeyPressed) {
        if (dwd->event.key.code == sfKeyEscape)
            sfRenderWindow_close(dwd->window);
    }
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        event_reload(dwd, s_and_m, t_spr);
        event_shoot(dwd, s_and_m, t_spr, m_scp);
    }
}

void events(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
            t_sprite_t *t_spr)
{
    sfRenderWindow_drawSprite(dwd->window, t_spr->bird.sprite, NULL);
    sfRenderWindow_drawText(dwd->window, t_spr->score.text, NULL);
    sfText_setString(t_spr->score.text_score, my_itoa(t_spr->score.score));
    sfRenderWindow_drawText(dwd->window, t_spr->score.text_score, NULL);
    ini_mouse_scope(dwd, m_scp);
    sfSprite_move(t_spr->bird.sprite, t_spr->bird.speed);
    nexus_life(t_spr);
    disp_bar(dwd, t_spr);
    sfRenderWindow_drawSprite(dwd->window, t_spr->bar.s_ammo, NULL);
    if (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
        in_event(dwd, s_and_m, m_scp, t_spr);
    }
    sfRenderWindow_display(dwd->window);
}
