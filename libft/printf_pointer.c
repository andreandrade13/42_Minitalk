/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andchris <andchris1987@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:58:59 by andchris          #+#    #+#             */
/*   Updated: 2022/08/30 21:03:11 by andchris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_pointer(unsigned long int pointer)
{
	int		i;
	int		result;
	char	*base;
	char	conversion[16];

	i = 0;
	base = "0123456789abcdef";
	if (pointer == 0)
	{
		return (write(1, "0x0", 3));
	}
	while (pointer > 0)
	{
		conversion[i++] = base[pointer % 16];
		pointer /= 16;
	}
	result = printf_str("0x");
	while (--i >= 0)
		result += write(1, &conversion[i], 1);
	return (result);
}
