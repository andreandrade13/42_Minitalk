/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andchris <andchris1987@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:57:15 by andchris          #+#    #+#             */
/*   Updated: 2022/08/30 21:03:41 by andchris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"

void    send_bit(int pid, char *str, size_t len)
{
    int     shift;
    size_t  i;

    i = 0;
    while (i <= len)
    {
        shift = 0;
        while (shift < 7)
        {
            if ((str[i] >> shift) & 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            shift++;
            usleep(300);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int     pid;
    char    *str;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        str = argv[2];
        send_bit(pid, str, ft_strlen(str));
    }
    else
        ft_printf("\nAre you sure there are 3 args? (e.g. ./client <PID> <STRING>)\n\n");
}