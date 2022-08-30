/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andchris <andchris1987@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:41:56 by andchris          #+#    #+#             */
/*   Updated: 2022/08/30 21:03:21 by andchris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	printf_u(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}	
	else if (nb > 0 && nb < 10)
	{
		nb += '0';
		i += ft_putchar(nb);
	}
	else
	{
		i += printf_u(nb / 10);
		nb = nb % 10 + '0';
		i += ft_putchar(nb);
	}
	return (i);
}
