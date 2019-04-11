/*
** EPITECH PROJECT, 2018
** disp_picture
** File description:
**
*/

#include "my.h"

int find_size_of_file(char const *filepath)
{
    struct stat buf;
    int size;

    stat(filepath, &buf);
    size = buf.st_size;
    return size;
}

void high_score(t_sprite_t *t_spr)
{
    int fd = open("highest_score", O_RDWR);
    int fd2 = open("highest_score", O_WRONLY);
    int size = find_size_of_file("highest_score");
    char *highest = malloc(sizeof(char) * (size + 1));
    char *save_high = malloc(size + int_len(t_spr->score.score));

    save_high = highest;
    read(fd, highest, size);
    highest[size] = '\0';
    save_high = highest;
    if (my_atoi(highest) < t_spr->score.score) {
        write(fd2, my_itoa(t_spr->score.score), int_len(t_spr->score.score));
        save_high = my_itoa(t_spr->score.score);
    }
    t_spr->h_score.hsave_score = save_high;
    close(fd);
}

void my_hunter(void)
{
    d_window_t dwd;
    s_music_t s_and_m;
    m_scope_t m_scp;
    t_sprite_t t_spr;

    set_bird(&t_spr);
    start_cond(&dwd, &s_and_m, &m_scp, &t_spr);
    sfRenderWindow_setFramerateLimit(dwd.window, 120);
    highest_score(&t_spr);
    while (sfRenderWindow_isOpen(dwd.window)) {
        cond_menu(&dwd, &s_and_m, &m_scp, &t_spr);
        sfRenderWindow_drawSprite(dwd.window, t_spr.bar.s_ammo, NULL);
        bird_animation(&t_spr);
        background(&dwd);
        events(&dwd, &s_and_m, &m_scp, &t_spr);
        game_over_menu(&dwd, &s_and_m, &t_spr, &m_scp);
    }
    destroy_all(&dwd, &s_and_m, &m_scp, &t_spr);
}

int main(int ac, char **av, char **env)
{
    int fd = open("read_me", O_RDONLY);
    int size = find_size_of_file("read_me");
    char *buffer = malloc(sizeof(char) * (size + 1));
    char *save_buffer = buffer;

    if (env[0] == NULL)
        return (84);
    if (ac < 1 || ac > 2)
        return (84);
    if (ac == 1)
        my_hunter();
    else if ((my_strcmp(av[0], "./my_hunter") == 0) &&
            (my_strcmp(av[1], "-h") == 0)) {
        read(fd, buffer, size);
        write(1, buffer, size);
    }
    free(save_buffer);
    close(fd);
    return (0);
}
