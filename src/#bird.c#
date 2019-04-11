/*
** EPITECH PROJECT, 2018
** bird
** File description:
** ini the bird
*/

#include "my.h"

void clock_bird(t_sprite_t *t_spr)
{
    t_spr->bird.time_bird = sfClock_getElapsedTime(t_spr->bird.clock_bird);
    t_spr->bird.sec_bird = t_spr->bird.time_bird.microseconds / 1000000.0f;
}

void bird_animation(t_sprite_t *t_spr)
{
    clock_bird(t_spr);
    if (t_spr->bird.sec_bird > 0.1) {
        if (t_spr->bird.area.top >= 200)
            t_spr->bird.reset = 1;
        if (t_spr->bird.area.top <= 0)
            t_spr->bird.reset = 0;
        if (t_spr->bird.reset == 0)
            t_spr->bird.area.top += 100;
        if (t_spr->bird.reset == 1)
            t_spr->bird.area.top -= 100;
        sfSprite_setTextureRect(t_spr->bird.sprite, t_spr->bird.area);
        sfClock_restart(t_spr->bird.clock_bird);
    }
}

void hit_box_part2(t_sprite_t *t_spr, sfVector2f pos_sprite, sfVector2i m_pos)
{
    if (m_pos.x >= (pos_sprite.x + 6) && m_pos.x <= (pos_sprite.x + 27)
        && m_pos.y >= (pos_sprite.y + 20) && m_pos.y <= (pos_sprite.y + 64)) {
        sfSprite_setPosition(t_spr->bird.sprite, t_spr->bird.pos_pop);
        t_spr->bird.speed.x += 0.1;
        t_spr->score.score += 5;
    }
}

void hit_box(m_scope_t *m_scp, t_sprite_t *t_spr)
{
    sfVector2f pos_sprite = sfSprite_getPosition(t_spr->bird.sprite);
    sfVector2i m_pos = m_scp->mouse_pos;

    t_spr->bullet = 0;
    if (m_pos.x >= (pos_sprite.x + 28) && m_pos.x <= (pos_sprite.x + 85) &&
        m_pos.y >= (pos_sprite.y + 30) && m_pos.y <= (pos_sprite.y + 75)) {
        t_spr->bird.pos_pop.y = rand() % 400;
        sfSprite_setPosition(t_spr->bird.sprite, t_spr->bird.pos_pop);
        t_spr->bird.speed.x += 0.2;
        t_spr->score.score += 15;
    }
    if (m_pos.x >= (pos_sprite.x + 68) && m_pos.x <= (pos_sprite.x + 103)
        && m_pos.y >= (pos_sprite.y + 8) && m_pos.y <= (pos_sprite.y + 45)) {
        sfSprite_setPosition(t_spr->bird.sprite, t_spr->bird.pos_pop);
        t_spr->bird.speed.x += 0.3;
        t_spr->score.score += 30;
    }
    hit_box_part2(t_spr, pos_sprite, m_pos);
}

void set_bird(t_sprite_t *t_spr)
{
    t_spr->bird.reset = 0;
    t_spr->bullet = 1;
    t_spr->bird.pos_pop.x = -400;
    t_spr->bird.pos_pop.y = rand()%400;
    t_spr->bird.area.left = 5;
    t_spr->bird.area.top = 0;
    t_spr->bird.area.height = 81;
    t_spr->bird.area.width = 110;
    t_spr->bird.speed.x = 1.75;
    t_spr->bird.texture = sfTexture_createFromFile
        ("assets/sprite/bird.png", NULL);
    t_spr->bird.sprite = sfSprite_create();
    sfSprite_setTexture(t_spr->bird.sprite, t_spr->bird.texture, sfTrue);
    sfSprite_setTextureRect(t_spr->bird.sprite, t_spr->bird.area);
    sfSprite_setPosition(t_spr->bird.sprite, t_spr->bird.pos_pop);
    t_spr->bird.clock_bird = sfClock_create();
    t_spr->nexus.life = 3;
}
