/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andchris <andchris1987@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:27:44 by andchris          #+#    #+#             */
/*   Updated: 2022/08/30 21:02:33 by andchris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printf_handler(const char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += (printf_c(va_arg(ap, int)));
	if (c == 's')
		i += (printf_str(va_arg(ap, char *)));
	if (c == 'p')
		i += (printf_pointer(va_arg(ap, unsigned long int)));
	if (c == 'd' || c == 'i')
		i += (printf_di(va_arg(ap, int)));
	if (c == 'u')
		i += (printf_u(va_arg(ap, unsigned int)));
	if (c == 'x')
		i += (printf_hex(va_arg(ap, int), "0123456789abcdef"));
	if (c == 'X')
		i += (printf_hex(va_arg(ap, int), "0123456789ABCDEF"));
	if (c == '%')
		i += (printf_percent());
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;

	va_start(ap, format);
	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			j += printf_handler(format[++i], ap);
		else
			j += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (j);
}
