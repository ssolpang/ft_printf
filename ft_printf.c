/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:10:26 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/31 20:54:52 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_format_and_print(va_list ap, char format)
{
	if (format == 'c')
		ft_char_format(ap);
	else if (format == 's')
		ft_string_format(ap);
	else if ((format == 'd') || (format == 'i'))
		ft_decimal_integer_format(ap);
	else if (format == 'p')
		ft_pointer_format(ap);
	else if (format == 'u')
		ft_unsigned_int_format(ap);
	else if (format == 'x')
		ft_hexa_format(ap, 'x');
	else if (format == 'X')
		ft_hexa_format(ap, 'X');
	else if (format == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			while (!ft_strchr("cspdiuxX%%", format[i + 1]))
				i++;
			ft_check_format_and_print(ap, format[i + 1]);
			i += 2;
		}
		if (format[i] && format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (i);
}
