/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** proto
*/

#ifndef MY_
#define MY_

/* include */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "window.h"
#include "music.h"
#include "sprite.h"

/* lib */

int my_strcmp(char const *s1, char const *s2);
char *my_itoa(int nb);
int my_atoi(char const *str);
int int_len(int nb);

/* set window */
sfRenderWindow *create_mywindow(unsigned int width, unsigned int height);
void background(d_window_t *dwd);
void ini_menu(d_window_t *dwd);
void ini_over(d_window_t *dwd);

/* start music */

void set_music(s_music_t *s_and_m);
sfMusic *music_create(void);
void sound_destroy(sfMusic *start_sound);

/* cond and destroy */

void start_cond(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
                t_sprite_t *t_spr);
void destroy_all(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
                t_sprite_t *t_spr);
void destroy_high_score(t_sprite_t *t_spr);

/* ini_sprite_proto */

void bullet(t_sprite_t *t_spr);
void set_pos_tab(t_sprite_t *t_spr);
void tab_init(t_sprite_t *t_spr);
void ini_score(t_sprite_t *t_spr);

/* events */

void in_event(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
                t_sprite_t *t_spr);
void events(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
            t_sprite_t *t_spr);
void event_shoot(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr,
                m_scope_t *m_scp);
void event_reload(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr);

/* bird */

void clock_bird(t_sprite_t *t_spr);
void bird_animation(t_sprite_t *t_spr);
void hit_box(m_scope_t *m_scp, t_sprite_t *t_spr);
void set_bird(t_sprite_t *t_spr);
void hit_box_part2(t_sprite_t *t_spr, sfVector2f pos_sprite, sfVector2i m_pos);

/* scope */

void ini_mouse_scope(d_window_t *dwd, m_scope_t *m_scp);

/* bar */

void nexus_life(t_sprite_t *t_spr);
void disp_bar(d_window_t *dwd, t_sprite_t *t_spr);

/* menu */

void lvl(d_window_t *dwd, t_sprite_t *t_spr);
void event_for_menu(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr);
void cond_menu(d_window_t *dwd, s_music_t *s_and_m, m_scope_t *m_scp,
                t_sprite_t *t_spr);
void event_for_over(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr);
void game_over_menu(d_window_t *dwd, s_music_t *s_and_m, t_sprite_t *t_spr,
                    m_scope_t *m_scp);
void hit_box_play(d_window_t *dwd);
void hit_box_over(d_window_t *dwd, t_sprite_t *t_spr);
void redef_score(d_window_t *dwd, t_sprite_t *t_spr);
void high_score(t_sprite_t *t_spr);
void highest_score(t_sprite_t *t_spr);
void ini_cond_menu(t_sprite_t *t_spr, d_window_t *dwd);

#endif
