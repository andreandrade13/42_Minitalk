/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andchris <andchris1987@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:03:57 by andchris          #+#    #+#             */
/*   Updated: 2022/09/13 19:09:53 by andchris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_message
{
    char    c;
    size_t  i;
}   t_message;

t_message   g_msg;

void    bit_handler(int bit)
{
    int i;

    i = 0;
    g_msg.c += ((bit & 1) << g_msg.i);
    g_msg.i++;
    if (g_msg.i == 7)
    {
        ft_printf("%c", g_msg.c);
        if (!g_msg.c)
            ft_printf("\n");
        g_msg.c = 0;
        g_msg.i = 0;
    }
}

int main(void)
{
    ft_printf("Server Online!\n");
    ft_printf("PID: %d\n", getpid());
    while (1)
    {
        signal(SIGUSR2, bit_handler);
        signal(SIGUSR1, bit_handler);
        pause();
    }
    return (0);
}