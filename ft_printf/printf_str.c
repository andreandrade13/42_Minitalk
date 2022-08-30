/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andchris <andchris1987@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:28:46 by andchris          #+#    #+#             */
/*   Updated: 2022/08/29 23:15:56 by andchris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		j += write(1, "(null)", 6);
	while (str[i])
	{
		j += write(1, &str[i], 1);
		++i;
	}
	return (j);
}
