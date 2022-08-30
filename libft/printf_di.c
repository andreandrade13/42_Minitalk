/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andchris <andchris1987@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:13:31 by andchris          #+#    #+#             */
/*   Updated: 2022/08/30 21:02:53 by andchris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_di(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i += printf_str("-2147483648");
	}
	else if (nb < 0)
	{
		nb *= -1;
		i += printf_c('-');
		i += printf_di(nb);
	}
	else if (nb >= 10)
	{
		i += printf_di(nb / 10);
		i += printf_di(nb % 10);
		return (i);
	}
	else
		i += printf_c(nb + '0');
	return (i);
}
