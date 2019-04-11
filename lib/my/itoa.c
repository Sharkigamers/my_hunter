/*
** EPITECH PROJECT, 2018
** itoa
** File description:
** transform int to char *
*/

#include <stdlib.h>

int my_compute_power_it(int nb, int p)
{
    int save_nb = nb;
    long nb2 = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    while (p > 1) {
        nb2 = save_nb * nb2;
        p --;
        if (nb2 > 2147483647 || nb2 < -2147483648)
            return (0);
    }
    return (nb2);
}

char my_itoc(int nb)
{
    return (nb + '0');
}

int int_len(int nb)
{
    int len = 0;

    if (nb < 0) {
        nb = -nb;
        len += 1;
    }
    for (;nb > 0; len++) {
        nb = nb / 10;
    }
    return (len);
}

char *cond_itoa(int nb, char *str, int i)
{
    if (nb == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return (str);
    }
    return (NULL);
}

char *my_itoa(int nb)
{
    int tmp = 0;
    int i = 0;
    int len = int_len(nb);
    int save_len = int_len(nb);
    char *str = malloc(sizeof(char) * (len + 2));

    if (nb < 0) {
        str[i] = '-';
        i++;
    }
    if (nb == 0)
        return (cond_itoa(nb, str, i));
    for (i = 0; i < save_len; i++) {
        len -= 1;
        tmp = nb / my_compute_power_it(10, len);
        str[i] = tmp + 48;
        nb = nb - (tmp * my_compute_power_it(10, len));
    }
    str[i] = '\0';
    return (str);
}
