/*
** EPITECH PROJECT, 2018
** scope
** File description:
** disp the sprite on cursor
*/

#include "my.h"

void ini_mouse_scope(d_window_t *dwd, m_scope_t *m_scp)
{
    m_scp->mouse_pos = sfMouse_getPositionRenderWindow(dwd->window);
    m_scp->pos.x = m_scp->mouse_pos.x;
    m_scp->pos.y = m_scp->mouse_pos.y;
    sfSprite_setTexture(m_scp->sprite_scope, m_scp->scope, sfTrue);
    sfSprite_setPosition(m_scp->sprite_scope, m_scp->pos);
    sfRenderWindow_drawSprite(dwd->window, m_scp->sprite_scope, NULL);
}
