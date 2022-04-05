/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:10:26 by jkwak             #+#    #+#             */
/*   Updated: 2022/04/05 16:21:26 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format_and_print(va_list ap, char format, int count)
{
	if (format == 'c')
		count = ft_char_format(ap, count);
	else if (format == 's')
		count = ft_string_format(ap, count);
	else if ((format == 'd') || (format == 'i'))
		count = ft_decimal_integer_format(ap, count);
	else if (format == 'p')
		count = ft_pointer_format(ap, count);
	else if (format == 'u')
		count = ft_unsigned_int_format(ap, count);
	else if (format == 'x')
		count = ft_hexa_format(ap, 'x', count);
	else if (format == 'X')
		count = ft_hexa_format(ap, 'X', count);
	else if (format == '%')
			{
				ft_putchar_fd('%', 1);
				count += 1;
			}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			while (!ft_strchr("cspdiuxX%%", format[i + 1]))
				i++;
			count = ft_check_format_and_print(ap, format[i + 1], count);
			i += 2;
		}
		if (format[i] && format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}
