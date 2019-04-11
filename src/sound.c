/*
** EPITECH PROJECT, 2018
** sound
** File description:
** set the sound
*/

#include "my.h"

void set_music(s_music_t *s_and_m)
{
    s_and_m->shoot = sfMusic_createFromFile("assets/effect/shoot_sniper.wav");
    s_and_m->reload = sfMusic_createFromFile("assets/effect/reload_sniper.wav");
    s_and_m->empty = sfMusic_createFromFile("assets/effect/no_bullet.wav");
}

sfMusic *music_create(void)
{
    sfMusic *loop_sound;

    loop_sound = sfMusic_createFromFile("assets/music/loop_music.wav");
    sfMusic_setLoop(loop_sound, sfTrue);
    sfMusic_play(loop_sound);
    return (loop_sound);
}

void sound_destroy(sfMusic *loop_sound)
{
    sfMusic_stop(loop_sound);
    sfMusic_destroy(loop_sound);
}
